#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
string input;
vector<long long> v;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input;
        reverse(input.begin(), input.end());
        v.push_back(stoll(input));
    }
    sort(v.begin(), v.end());
    for(auto i:v){
        cout<<i<<"\n";
    }
    return 0;
}