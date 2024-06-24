#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m;
char board[1000][1000];
int dist[1000][1000][2];

int bfs(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j][0]=-1;
            dist[i][j][1]=-1;
        }
    }
    queue<tuple<int,int,int>> Q;
    Q.push({0,0,0});
    dist[0][0][0]=1;
    dist[0][0][1]=1;
    while(!Q.empty()){
        int x, y, broken;
        tie(x,y,broken)=Q.front();
        if(x==n-1&&y==m-1) return dist[x][y][broken];
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny]=='0'&&dist[nx][ny][broken]==-1){
                dist[nx][ny][broken]=dist[x][y][broken]+1;
                Q.push({nx,ny,broken});
            }
            if(board[nx][ny]=='1'&&broken==0&&dist[nx][ny][broken]==-1){
                dist[nx][ny][1]=dist[x][y][0]+1;
                Q.push({nx,ny,1});
            }
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    cout<<bfs();
    return 0;
}