#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<int,int> arr[100000];
int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].second>>arr[i].first;
    }
    sort(arr,arr+n);
    int cnt=0;
    int before=0;
    for(int i=0;i<n;i++){
        if(before>arr[i].second) continue;
        cnt++;
        before=arr[i].first;
    }
    cout<<cnt;
}