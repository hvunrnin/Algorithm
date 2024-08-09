#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

class cmp {
public: 
    bool operator() (int a, int b){
        if(abs(a)!=abs(b)) return abs(a)>abs(b); // 절댓값이 a가 크면 바꾸는 거니까 내림차순
        return a>b; // 음수가 더 앞에 오도록
        // 같은 값이면 false 반환
    }
};

priority_queue<int, vector<int>, cmp> pq;
int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        int num;
        cin>>num;
        if(num!=0) pq.push(num);
        else{
            if(pq.empty()) cout<<"0\n";
            else {
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
    }
}