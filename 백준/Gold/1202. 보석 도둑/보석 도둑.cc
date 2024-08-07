#include <iostream>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int n,k;
pair<int,int> arr[300000];
multiset<int> bag;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i].second>>arr[i].first;
    }
    sort(arr,arr+n);
    while(k--){
        int num;
        cin>>num;
        bag.insert(num);
    }
    long long ans=0;
    for(int i=n-1;i>=0;i--){
        auto b=bag.lower_bound(arr[i].second);
        if(b==bag.end()) continue;
        ans+=arr[i].first;
        bag.erase(b);
    }
    cout<<ans;
}