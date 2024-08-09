#include <iostream>
#include <queue>
#include <vector>

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
        pq.push(num);
    }
    int sum=0;
    while(pq.size()>1){
        int a=pq.top(); pq.pop();
        int b=pq.top(); pq.pop();
        sum+=(a+b);
        pq.push(a+b);
    }
    cout<<sum;
}