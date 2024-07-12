#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[100000];

bool compare(int i, int j){
    return j<i;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,compare);
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,arr[i]*(i+1));
    }
    cout<<ans;
}