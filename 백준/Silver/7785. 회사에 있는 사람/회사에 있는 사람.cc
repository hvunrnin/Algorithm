#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int n;
unordered_set<string> s;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        string name;
        string input;
        cin>>name>>input;
        if(input=="enter") s.insert(name);
        else s.erase(name);
    }
    vector<string> v(s.begin(),s.end());
    sort(v.begin(),v.end(),greater<string>());
    for(auto c:v) cout<<c<<"\n";
}