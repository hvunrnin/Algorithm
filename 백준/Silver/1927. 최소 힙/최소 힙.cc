#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        int num;
        cin>>num;
        if(num==0){
            if(pq.empty()) cout<<"0\n";
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else{
            pq.push(num);
        }
    }
}