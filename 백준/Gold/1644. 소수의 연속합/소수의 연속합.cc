#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n;
vector<int> v;
int cnt;

void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            v.push_back(i);
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    sieve(n);
    //cout<<v.size();
    if(v.empty()){
        cout<<0;
        return 0;
    }
    int en=0;
    int sum=v[0];
    for(int st=0;st<v.size();st++){
        while(en<v.size()&&sum<n){
            en++;
            if(en!=v.size()) sum+=v[en];
        }
        if(sum==n) cnt++;
        if(en==v.size()) break;
        sum-=v[st];
    }
    cout<<cnt;
}