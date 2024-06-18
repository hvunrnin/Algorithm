#include <iostream>

using namespace std;

bool used[10];
int arr[10];
int n, m;

void func(int k){
    if(k==m){
        for(int i=0;i<k;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            arr[k]=i;
            used[i]=true;
            func(k+1);
            used[i]=false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    func(0);
}