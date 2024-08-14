// 한 명씩 저장
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int arr[51][51];
int ans[51];
vector<int> v;
vector<int> adj[51];
bool vis[51];

int bfs(int num){
    fill(vis,vis+50,0);
    queue<int> q;
    //q.push(num);
    vis[num]=true;
    for(auto c:adj[num]){
        q.push(c);
        vis[c]=true;
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto c:adj[cur]){
            if(arr[num][c]!=55||vis[c]) continue;
            arr[num][c]=arr[num][cur]+1;
            q.push(c);
            vis[c]=true;
        }
    }
    return *max_element(arr[num],arr[num]+n+1);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        fill(arr[i],arr[i]+n+1,55);
        arr[i][0]=0;
        arr[i][i]=0;
    }
    int num1=0,num2=0;
    while(1){
        cin>>num1;
        cin>>num2;
        if(num1==-1&&num2==-1) break;
        arr[num1][num2]=1;
        arr[num2][num1]=1;
        adj[num1].push_back(num2);
        adj[num2].push_back(num1);
    }
    for(int i=1;i<=n;i++){
        ans[i]=bfs(i);
    }
    cout<<*min_element(ans+1,ans+n+1)<<" ";
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(ans[i]==*min_element(ans+1,ans+n+1)){
            cnt++;
            v.push_back(i);
        }
    }
    cout<<cnt<<"\n";
    sort(v.begin(),v.end());
    for(auto c:v){
        cout<<c<<" ";
    }
}