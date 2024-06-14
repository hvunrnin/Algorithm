#include <iostream>

using namespace std;

int z_func(int n, int r, int c){
    if(n==0) return 0;
    int half=1<<(n-1);
    if(r<half&&c<half) return z_func(n-1,r,c); // 1사분면
    if(r<half&&c>=half) return half*half+z_func(n-1,r,c-half); //2
    if(r>=half&&c<half) return 2*half*half+z_func(n-1,r-half,c); //3
    return 3*half*half+z_func(n-1,r-half,c-half); //4
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,r,c;
    cin>>n>>r>>c;
    cout<<z_func(n,r,c);
}