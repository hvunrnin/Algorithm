#include <iostream>
#include <set>

using namespace std;

int t;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        multiset<int> ms;
        while(n--){
            char input;
            int num;
            cin>>input;
            if(input=='I'){
                cin>>num;
                ms.insert(num);
            }
            else{
                cin>>num;
                if(ms.empty()) continue;
                if(num==1){
                    ms.erase(prev(ms.end()));
                }
                else{
                    ms.erase(ms.begin());
                }
            }
        }
        if(ms.empty()) cout<<"EMPTY\n";
        else{
            cout<<*prev(ms.end())<<' '<<*ms.begin()<<"\n";
        }
    }
}