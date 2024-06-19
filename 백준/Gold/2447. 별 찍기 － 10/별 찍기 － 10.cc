#include <iostream>
#include <algorithm>

using namespace std;

int n;
char board[6600][6600];

void rec(int n, int x, int y){
    if(n==1) return;
    for(int i=x+n/3;i<x+2*n/3;i++){
        for(int j=y+n/3;j<y+2*n/3;j++){
            board[i][j]=' ';
        }
    }
    rec(n/3,x,y);
    rec(n/3,x,y+n/3);
    rec(n/3,x,y+2*n/3);
    rec(n/3,x+n/3,y);
    rec(n/3,x+n/3,y+2*n/3);
    rec(n/3,x+2*n/3,y);
    rec(n/3,x+2*n/3,y+n/3);
    rec(n/3,x+2*n/3,y+2*n/3);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            board[i][j] = '*';
        }
    }
    rec(n,0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
}