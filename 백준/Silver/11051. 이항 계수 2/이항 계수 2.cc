#include <iostream>

using namespace std;

int arr[1001][1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        arr[i][i]=1;
        arr[i][0]=1;
        for(int j=1;j<i;j++){
            arr[i][j]=(arr[i-1][j-1]+arr[i-1][j])%10007;
        }
    }
    cout<<arr[n][k];
    return 0;
}