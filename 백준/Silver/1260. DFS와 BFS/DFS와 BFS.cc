#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,st;
vector<int> adj[1001];
bool vis[1001];

void dfs(int n){
    vis[n]=true;
    cout<<n<<" ";
    for(auto nxt:adj[n]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

void bfs(){
    queue<int> q;
    q.push(st);
    vis[st]=true;
    while(!q.empty()){
        int cur=q.front();
        cout<<cur<<" ";
        q.pop();
        for(auto nxt:adj[cur]){
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt]=true;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>st;
    while(m--){
        int num1,num2;
        cin>>num1>>num2;
        adj[num1].push_back(num2);
        adj[num2].push_back(num1);
    }
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());

    }
    dfs(st);
    fill(vis+1,vis+n+1,false);
    cout<<"\n";
    bfs();
}   