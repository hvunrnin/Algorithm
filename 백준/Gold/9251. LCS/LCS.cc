#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int lcs[1001][1001]={0};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a_string, b_string;
    cin>>a_string>>b_string;
    //lcs[0][0]=0;
    for(int i=1;i<=a_string.length();i++){
        for(int j=1;j<=b_string.length();j++){
            if(a_string[i-1]==b_string[j-1]){
                lcs[i][j]=lcs[i-1][j-1]+1;
            }
            else{
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    cout<<lcs[a_string.length()][b_string.length()];
}