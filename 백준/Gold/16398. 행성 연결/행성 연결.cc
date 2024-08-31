#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

int parent[1001];
vector< tuple<int,int,int> > edge;
int n;

int find(int a){
    if(parent[a]==a) return a;
    return parent[a]=find(parent[a]);
}

void merge(int a, int b){
    a=find(a);
    b=find(b);
    parent[a]=b;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int cost;
            cin>>cost;
            if(i>=j) continue;
            //edge[num++]={cost,i,j};
            edge.push_back({cost,i,j});
        }
    }
    sort(edge.begin(), edge.end());
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    int cnt=0;
    long long ans=0;
    for(auto e : edge){
        int a, b,c;
        tie(c,a,b)=e;
        if(find(a)==find(b)) continue;
        merge(a,b);
        ans+=c;
        cnt++;
        if(cnt==n-1) break;
    }
    cout<<ans;
}