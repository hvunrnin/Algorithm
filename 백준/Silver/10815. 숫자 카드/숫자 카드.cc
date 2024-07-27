#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<int> v;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  while(n--){
    int num;
    cin>>num;
    v.push_back(num);
  }
  sort(v.begin(),v.end());
  cin>>m;
  while(m--){
    int input;
    cin>>input;
    cout<<binary_search(v.begin(),v.end(),input)<<" ";
  }
}