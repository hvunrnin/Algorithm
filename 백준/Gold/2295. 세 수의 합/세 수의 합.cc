#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

int n;
int arr[1000];
vector<int> v;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            v.push_back(arr[i]+arr[j]);
        }
    }
    sort(v.begin(),v.end());
    for(int i=n-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
            if(binary_search(v.begin(),v.end(),arr[i]-arr[j])){
                cout<<arr[i];
                return 0;
            }
        }
    }
}