#include <iostream>

using namespace std;

int t,n;
int arr[11];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    while(t--){
        cin>>n;
        for(int i=4;i<=n;i++){
            arr[i]=arr[i-3]+arr[i-2]+arr[i-1];
        }
        cout<<arr[n]<<"\n";
    }
}