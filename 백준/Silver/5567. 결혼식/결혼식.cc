#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[501];
bool vis[501];
int n,m;

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
    vis[1]=true;
    int cnt=0;
    for(auto c1 : adj[1]){
        if(!vis[c1]){
            cnt++;
            vis[c1]=true;
        }
        for(auto c2 : adj[c1]){
            if(vis[c2]) continue;
            vis[c2]=true;
            cnt++;
        }
    }
    cout<<cnt;
}