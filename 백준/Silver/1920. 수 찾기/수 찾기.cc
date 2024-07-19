#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int arr[100000];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int m;
    cin>>m;
    while(m--){
        int num;
        cin>>num;
        cout<<binary_search(arr, arr+n, num)<<"\n";
    }
    return 0;
}