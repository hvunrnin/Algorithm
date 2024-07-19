#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int num=1;
    for(int i=0;i<k;i++){
        num*=(n-i);
    }
    for(int i=2;i<=k;i++){
        num/=i;
    }
    cout<<num;
}