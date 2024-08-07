#include <iostream>
#include <unordered_map>

using namespace std;

int n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        int num;
        cin>>num;
        unordered_map<string,int> m;
        while(num--){
            string input, type;
            cin>>input>>type;
            int cnt=0;
            if(m.find(type)!=m.end()) cnt=m[type];
            cnt++;
            m[type]=cnt;
        }
        int ans=1;
        for(auto e : m){
            ans*=(e.second+1);
        }
        cout<<ans-1<<"\n";
    }
}