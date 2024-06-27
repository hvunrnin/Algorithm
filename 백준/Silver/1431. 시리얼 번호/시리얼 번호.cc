#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int n;
string input[50];

bool func(const string&a, const string&b){
    if(a.size()!=b.size()){
        return a.size()<b.size();
    }
    int sumA=0;
    int sumB=0;
    for(int i=0;i<a.size();i++){
        if(isdigit(a[i])){
            sumA+=(a[i]-'0');
        }
    }
    for(int i=0;i<b.size();i++){
        if(isdigit(b[i])){
            sumB+=(b[i]-'0');
        }
    }
    if(sumA!=sumB){
        return sumA<sumB;
    }
    return a<b;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    sort(input, input+n, func);
    for(int i=0;i<n;i++){
        cout<<input[i]<<"\n";
    }
}