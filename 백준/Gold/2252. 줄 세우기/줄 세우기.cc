#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<int> adj[32001];
vector<int> ans;
queue<int> q;
int dgr[32001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        dgr[b]++;
    }
    for(int i=1;i<=n;i++){
        if(dgr[i]==0) q.push(i);
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        ans.push_back(cur);
        for(int nxt:adj[cur]){
            dgr[nxt]--;
            if(dgr[nxt]==0) q.push(nxt);
        }
    }
    for(auto c:ans){
        cout<<c<<" ";
    }
}