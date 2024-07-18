#include <iostream>
#include <vector>

using namespace std;

int n;
vector <pair<int,int>> v;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a=0,b=0,c=0,d=0;
        cin>>a>>b>>c>>d;
        v.push_back({a*100+b,c*100+d});
    }
    int ans=0;
    int t=301;
    while(t<1200){
        int nxt=t;
        for(int i=0;i<n;i++){
            if(v[i].first<=t&&v[i].second>nxt){
                nxt=v[i].second;
            }
        }
        if(nxt==t){
            cout<<0;
            return 0;
        }
        ans++;
        t=nxt;
    }
    cout<<ans;
}