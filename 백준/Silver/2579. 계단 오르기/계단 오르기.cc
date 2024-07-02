#include <iostream>

using namespace std;

int t;
int arr[301];
int sum[301];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>arr[i];
    }
    sum[1] = arr[1];
    if(t == 1){
        cout << sum[1];
        return 0;
    }
    sum[2] = arr[1] + arr[2];
    if(t == 2){
        cout << sum[2];
        return 0;
    }
    sum[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
    for(int i = 4; i <= t; i++){
        sum[i] = max(sum[i-2] + arr[i], sum[i-3] + arr[i-1] + arr[i]);
    }
    cout << sum[t];
    return 0;
}
