#include <iostream>
#include <algorithm>

using namespace std;

int n,s;
int arr[100000];
int mn=0x7fffffff;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0;i<n;i++) cin>>arr[i];
    int en=0;
    int sum=arr[0];
    for(int st=0;st<n;st++){
        //int sum=arr[st];
        while(sum<s&&en<n){
            en++;
            if(en!=n) sum+=arr[en];
        }
        if(en==n) break;
        mn=min(en-st+1,mn);
        sum-=arr[st];
    }
    if(mn==0x7fffffff) mn=0;
    cout<<mn;
}