#include <iostream>
#include <string>

using namespace std;

int video[64][64];

void press(int n, int x, int y){
    bool allsame=true;
    for(int i=x;i<x+n;i++){
        for(int j=y;j<y+n;j++){
            if(video[x][y]!=video[i][j]){
                allsame=false;
                break;
            }
        }
        if(!allsame) break;
    }
    if(allsame){
        cout<<video[x][y];
        return;
    }
    cout<<"(";
    press(n/2,x,y);
    press(n/2,x,y+n/2);
    press(n/2,x+n/2,y);
    press(n/2,x+n/2,y+n/2);
    cout<<")";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string line;
    for(int i=0;i<n;i++){
        cin>>line;
        for(int j=0;j<n;j++){
            video[i][j]=line[j]-'0';
        }
        //cin>>video[i];
    }
    press(n, 0, 0);
}