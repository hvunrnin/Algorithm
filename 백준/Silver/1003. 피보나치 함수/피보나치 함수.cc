#include <iostream>

using namespace std;

int t;
int zero_arr[50], one_arr[50];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    zero_arr[0]=1;
    zero_arr[1]=0;
    one_arr[0]=0;
    one_arr[1]=1;
    for(int i=2;i<=40;i++){
        zero_arr[i]=zero_arr[i-1]+zero_arr[i-2];
        one_arr[i]=one_arr[i-1]+one_arr[i-2];
    }
    while(t--){
        int n;
        cin>>n;
        cout<<zero_arr[n]<<' '<<one_arr[n]<<"\n";
    }
}