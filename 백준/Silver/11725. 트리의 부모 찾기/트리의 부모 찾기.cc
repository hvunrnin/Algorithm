#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int par[100001];
vector<int> adj[100001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int c:adj[cur]){
            if(par[cur]==c) continue;
            q.push(c);
            par[c]=cur;
        }
    }
    for(int i=2;i<=n;i++){
        cout<<par[i]<<"\n";
    }
}