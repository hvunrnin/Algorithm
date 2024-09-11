#include <iostream>

using namespace std;

// memset 사용 용이, 2배를 해도 int 범위여서 아래 상수를 무한대로 보통 선언
const int INF = 0x3f3f3f3f;
int d[101][101];
int n,m;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        // 테이블을 모두 무한대로 초기화
        fill(d[i],d[i]+n+1,INF);
    }
    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        // 간선 1개로 바로 건너갈 수 있는 곳 채우기
        d[a][b]=min(d[a][b],c);
    }
    for(int i=1;i<=n;i++){
        // 자기 자신으로 가는 거리 0
        d[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // 1부터 n까지 순서대로 다 확인하여 최단거리 채우기
                // ex. D[s][t]를 D[s][!]+D[!][t]가 더 작으면 바꿔주기
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]==INF) cout<<"0 ";
            else cout<<d[i][j]<<' ';
        }
        cout<<"\n";
    }
}