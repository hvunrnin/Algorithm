#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
vector<int> adj[1001];
bool vis[1001];

int bfs(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i]=true;
        cnt++;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt]=true;
            }
        }
    }
    return cnt;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int num1,num2;
        cin>>num1>>num2;
        adj[num1].push_back(num2);
        adj[num2].push_back(num1);
    }
    cout<<bfs();
}   