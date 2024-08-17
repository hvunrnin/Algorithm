#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<int> adj[1001];
queue<int> q;
int dgr[1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int num;
        cin>>num;
        int arr[1001];
        for(int i=0;i<num;i++){
            cin>>arr[i];
        }
        for(int i=1;i<num;i++){
            adj[arr[i-1]].push_back(arr[i]);
            dgr[arr[i]]++;
        }
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(dgr[i]==0) q.push(i);
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        ans.push_back(cur);
        for(auto nxt:adj[cur]){
            dgr[nxt]--;
            if(dgr[nxt]==0) q.push(nxt);
        }
    }
    if(ans.size()!=n){
        cout<<"0";
    }
    else{
        for(auto c:ans){
        cout<<c<<"\n";
    }
    }
}