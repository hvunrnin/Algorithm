#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
vector<int> adj[1001];
vector<int> ans[1001];
map<string, int> fam;
int dgr[1001];
string name[1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>name[i];
    }
    sort(name+1,name+n+1);
    for(int i=1;i<=n;i++){
        fam[name[i]]=i;
    }
    cin>>m;
    while(m--){
        string input1, input2;
        cin>>input1>>input2;
        adj[fam[input2]].push_back(fam[input1]);
        dgr[fam[input1]]++;
    }
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(dgr[i]==0) v.push_back(i);
    }
    cout<<v.size()<<"\n";
    for(auto c:v){
        cout<<name[c]<<' ';
    }
    cout<<"\n";
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());
        for(auto c:adj[i]){
            if(dgr[c]-dgr[i]==1) ans[i].push_back(c);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<name[i]<<' '<<ans[i].size()<<' ';
        for(auto c:ans[i]) cout<<c<<' ';
        cout<<"\n";
    }
}