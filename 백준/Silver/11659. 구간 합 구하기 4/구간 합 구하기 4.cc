// 시간 복잡도 생각해서 누적합 사용해야함
#include <iostream>

using namespace std;

int n,m;
int arr[100000], sum[100000];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    sum[0]=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    while(m--){
        int i,j;
        cin>>i>>j;
        cout<<sum[j-1]-sum[i-2]<<"\n";
    }
}