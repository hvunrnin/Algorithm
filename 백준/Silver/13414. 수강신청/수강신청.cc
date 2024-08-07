#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int k,l;
unordered_map<string, int> m;

bool compare(const pair<string,int>& v1, const pair<string,int>& v2){
    return v1.second<v2.second;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>k>>l;
    for(int i=1;i<=l;i++){
        string input;
        cin>>input;
        m[input]=i;
    }
    vector<pair<string,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),compare);
    k=min(k,(int)v.size());
    for(int i=0;i<k;i++){
        cout<<v[i].first<<"\n";
    }
}