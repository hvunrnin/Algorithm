#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int m,n,k;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int board[100][100];
int vis[100][100];
int ans[10000];
#define X first
#define Y second

void square(int x1, int y1, int x2, int y2){
    for(int i=y1;i<y2;i++){
        for(int j=x1;j<x2;j++){
            if(board[i][j]==0){
                board[i][j]=1;
            }
        }
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n>>k;
    int x1, y1, x2, y2;
    while(k--){
        cin>>x1>>y1>>x2>>y2;
        square(x1, y1, x2, y2);
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int area=0;
            if(board[i][j]==1||vis[i][j]) continue;
            queue <pair<int,int> > Q;
            Q.push({i,j});
            vis[i][j]=1;
            while(!Q.empty()){
                auto cur = Q.front();
                Q.pop();
                area++;
                for(int dir=0;dir<4;dir++){
                    int nx = cur.X+dx[dir];
                    int ny = cur.Y+dy[dir];
                    if(nx<0||nx>=m||ny<0||ny>=n) continue;
                    if(vis[nx][ny]||board[nx][ny]==1) continue;
                    vis[nx][ny]=1;
                    Q.push({nx,ny});
                }
            }
            ans[cnt]=area;
            cnt++;
        }
    }
    cout<<cnt<<'\n';
    sort(ans,ans+cnt);
    for(int i=0;i<cnt;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}