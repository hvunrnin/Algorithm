#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
int d[101][101];
int nxt[101][101];
int n,m;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fill(d[i],d[i]+n+1,INF);
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c);
        nxt[a][b]=b;
    }
    for(int i=1;i<=n;i++){
        d[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    nxt[i][j]=nxt[i][k]; // i에서 다음으로 가는 게 k니까 nxt[i][j]를 변경
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]==INF) cout<<"0 ";
            else cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]==0||d[i][j]==INF){
                cout<<"0\n";
                continue;
            }
            vector<int> path;
            int st=i;
            while(st!=j){
                path.push_back(st); // 모든 경로 다 집어넣기 
                st=nxt[st][j]; // k에서 j로 한 단계씩 가야됨
            }
            path.push_back(j);
            cout<<path.size()<<" ";
            for(auto c:path) cout<<c<<" ";
            cout<<"\n";
        }
    }
}