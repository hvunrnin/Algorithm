#include <iostream>

using namespace std;

int n;
int dist[1000001], pre[1000001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    dist[1]=0;
    for(int i=2;i<=n;i++){
        dist[i]=dist[i-1]+1;
        pre[i]=i-1;
        if(i%2==0&&dist[i]>dist[i/2]+1){
            dist[i]=dist[i/2]+1;
            pre[i]=i/2;
        }
        if(i%3==0&&dist[i]>dist[i/3]+1){
            dist[i]=dist[i/3]+1;
            pre[i]=i/3;
        }
    }
    cout<<dist[n]<<"\n";
    int cur=n;
    while(1){
        cout<<cur<<' ';
        if(cur==1) break;
        cur=pre[cur];
    }
}