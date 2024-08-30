#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int parent[100001];
int v,e;
tuple<int,int,int> edge[100001]; 

int find(int u){
    if(u==parent[u]) return u;
    return find(parent[u]);
}

void merge(int u, int v){
    u=find(u);
    v=find(v);
    parent[u]=v;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>v;
    for(int i=1;i<=v;i++){
        int cost;
        cin>>cost;
        edge[e++]={cost,i,v+1};
    }
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            int cost;
            cin>>cost;
            if(i>=j) continue;
            edge[e++]={cost,i,j};
        }
    }
    sort(edge, edge+e);
    v++;
    for(int i=1;i<=v;i++){
        parent[i]=i;
    }
    int cnt=0;
    int ans=0;
    for(int i=0;i<e;i++){
        int a, b, cost;
        tie(cost,a,b)=edge[i];
        if(find(a)==find(b)) continue;
        merge(a,b);
        ans+=cost;
        cnt++;
        if(cnt==v-1) break;
    }
    cout<<ans;
}