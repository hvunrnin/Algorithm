#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a_cnt, b_cnt;
vector<int> a;
vector<int> b;
vector<int> ans;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>a_cnt>>b_cnt;
  while(a_cnt--){
    int num;
    cin>>num;
    a.push_back(num);
  }
  while(b_cnt--){
    int num;
    cin>>num;
    b.push_back(num);
  }
  sort(b.begin(),b.end());
  int cnt=0;
  for(int c:a){
    if(!binary_search(b.begin(),b.end(),c)){
      cnt++;
      ans.push_back(c);
    }
  }
  sort(ans.begin(),ans.end());
  cout<<cnt<<"\n";
  for(int c:ans){
    cout<<c<<" ";
  }
}