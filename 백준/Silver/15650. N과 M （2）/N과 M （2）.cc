#include <iostream>

using namespace std;

int arr[8];
int used[8];
int n,m;

void func(int k){ // k번째까지 뽑은 거
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    int start=1;
    if(k!=0){
        start=arr[k-1]+1;
    }
    for(int i=start;i<=n;i++){
        if(used[k]==0){
            arr[k]=i;
            used[k]=1;
            func(k+1);
            used[k]=0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    func(0);
}