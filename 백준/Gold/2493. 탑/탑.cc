#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    stack<pair<int,int>> S;
    S.push({100000001,0});
    for(int i=1;i<=n;i++){
        int tower;
        cin>>tower;
        int ans = 0;
        while(tower>S.top().first){
            S.pop();
        }
        cout<<S.top().second<<" ";
        S.push({tower, i});
    }
}