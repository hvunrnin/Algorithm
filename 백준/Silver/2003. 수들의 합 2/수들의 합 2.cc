#include <iostream>

using namespace std;

int n,m;
int arr[10000];
int cnt;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int en=0;
    int sum=arr[0];
    for(int st=0;st<n;st++){
        while(en<n&&sum<m){
            en++;
            if(en!=n) sum+=arr[en];
        }
        if(en==n) break;
        if(sum==m) cnt++;
        sum-=arr[st];
    }
    cout<<cnt;
}