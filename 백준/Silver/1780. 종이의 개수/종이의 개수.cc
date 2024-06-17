#include <iostream>

using namespace std;

int paper[2200][2200];
int cnt[3];

void cut(int n, int x, int y){
    bool allsame = true;
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(paper[x][y]!=paper[i][j]){
                allsame=false;
                break;
            }
        }
        if(!allsame) break;
    }
    if(allsame){
        cnt[paper[x][y]+1]++;
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cut(n/3,x+i*n/3,y+j*n/3);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>paper[i][j];
        }
    }
    cut(n,0,0);
    for(int i=0;i<3;i++){
        cout<<cnt[i]<<"\n";
    }
}