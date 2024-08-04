//투 포인터 방법 (이분 탐색 방법도 존재 lower_bound 써서)
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[1000000];
int mn=0x7fffffff;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int en=0;
    for(int st=0;st<n;st++){
        while(en<n&&arr[en]-arr[st]<m) en++;
        if(en==n) break;
        mn=min(mn,arr[en]-arr[st]);
    }
    cout<<mn;
}