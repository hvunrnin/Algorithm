#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<>> pq;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n*n;i++){
        int num;
        cin>>num;
        pq.push(num);
        if(n<(int)pq.size()) pq.pop(); // 메모리 초과 나와서 큰 5개만 가져가기
    }
    cout<<pq.top();
}