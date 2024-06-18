#include <iostream>

using namespace std;

bool used_x[30];
bool used_xy1[30];
bool used_xy2[30];
int n,cnt;

void func(int k){
    if(k==n){
        cnt++;
        return;
    }
    for(int i=0;i<n;i++){
        if(used_x[i]||used_xy1[i+k]||used_xy2[k-i+n-1]) continue;
        used_x[i]=true;
        used_xy1[i+k]=true;
        used_xy2[k-i+n-1]=true;
        func(k+1);
        used_x[i]=false;
        used_xy1[i+k]=false;
        used_xy2[k-i+n-1]=false;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    func(0);
    cout<<cnt;
}