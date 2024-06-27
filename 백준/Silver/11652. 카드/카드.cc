#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[100000];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int cnt, num_cnt=0;
    cnt=1;
    long long num=arr[0];
    num=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            cnt++;
        }
        else{
            if(cnt>num_cnt){
                num_cnt=cnt;
                num=arr[i-1];
            }
            cnt=1;
        }
    }
    if(cnt>num_cnt){
        num=arr[n-1];
    }
    cout<<num;
}