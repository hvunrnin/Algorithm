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
    return parent[u]=find(parent[u]);
}

void merge(int u, int v){
    u=find(u);
    v=find(v);
    parent[u]=v;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[i]={c,a,b};
    }
    sort(edge, edge+e);
    for(int i=1;i<=v;i++){
        parent[i]=i;
    }
    int cnt=0,ans=0;
    for(int i=0;i<e;i++){
        int a,b,c;
        tie(c,a,b)=edge[i];
        if(find(a)==find(b)) continue;
        merge(a,b);
        ans+=c;
        cnt++;
        if(cnt==v-1) break;
    }
    cout<<ans;
}