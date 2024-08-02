#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v;

bool solve(int n){
  long long sum=0;
  for(auto c:v){
    if(c>n){
      sum+=(c-n);
    }
  }
  if(sum>=m) return true;
  return false;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  while(n--){
    int num;
    cin>>num;
    v.push_back(num);
  }
  int st=0;
  int en=*max_element(v.begin(),v.end());
  while(st<en){
    int mid=(st+en+1)/2;
    if(solve(mid)) st=mid;
    else{
      en=mid-1;
    }
  }
  cout<<st;
}