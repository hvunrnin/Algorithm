#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<int> v;
vector<int> tmp;
vector<int> rv;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int m=n;
    while(m--){
        int input;
        cin>>input;
        v.push_back(input);
        tmp.push_back(input);

    }
    sort(v.begin(),v.end());
    rv.push_back(v[0]);
    for(int i=1;i<n;i++){
        if(v[i]!=v[i-1]) rv.push_back(v[i]);
    }
    for(int i=0;i<n;i++){
        //int upper = upper_bound(rv.begin(),rv.end(),v[i])-rv.begin();
        int lower = lower_bound(rv.begin(),rv.end(),tmp[i])-rv.begin();
        cout<<lower<<" ";
    }
}