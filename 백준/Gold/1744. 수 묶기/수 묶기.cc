#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> pos;
vector<int> neg;
int one_cnt, zero_cnt;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a>1) pos.push_back(a);
        else if(a==1) one_cnt++;
        else if(a==0) zero_cnt++;
        else neg.push_back(a);
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    int sum=0;
    for(int i=pos.size()-1;i>-1;i-=2){
        if(i==0){
            sum+=pos[i];
        }
        else{
            sum+=pos[i]*pos[i-1];
        }
    }
    for(int i=0;i<neg.size();i+=2){
        if(i==neg.size()-1){
            if(zero_cnt==0) sum+=neg[i];
        }
        else{
            sum+=neg[i]*neg[i+1];
        }
    }
    sum+=one_cnt;
    cout<<sum;
}