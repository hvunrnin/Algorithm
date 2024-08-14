// 스택 형식으로 dfs 함수 작성
// 시작-목표로 해서 이어지면 1
// 한 칸씩 모두 함수 넣어서 각각 확인
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//vector<int> adj[101];
int arr[100][100];
bool vis[100];
int n;

bool dfs(int st, int en){
    stack<int> s;
    fill(vis,vis+100,0);
    s.push(st);
    while(!s.empty()){
        int cur=s.top();
        s.pop();
        // for(auto c:adj[cur]){
        //     if(vis[c]) continue;
        //     if(c==en) return true;
        //     s.push(c);
        // }
        for(int i=0;i<n;i++){
            if(arr[cur][i]){
                if(vis[i]) continue;
                if(i==en) return true;
                s.push(i);
                vis[i]=true;
            }
        }
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dfs(i,j)<<" ";
        }
        cout<<"\n";
    }
}