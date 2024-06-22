#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int input[10];
int used[10];
int m,n;

void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            arr[k]=input[i];
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
    for(int i=0;i<n;i++){
        int num=0;
        cin>>num;
        input[i]=num;
    }
    sort(input, input+n);
    func(0);
}