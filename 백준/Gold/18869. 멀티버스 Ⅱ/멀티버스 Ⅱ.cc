#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100][100000];
int m,n;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        vector<int> v(arr[i],arr[i]+n);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int j=0;j<n;j++){
            arr[i][j]=lower_bound(v.begin(),v.end(),arr[i][j])-v.begin();
        }
    }
    int cnt=0;
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            bool chk = true;
            for(int k=0;k<n;k++){
                if(arr[i][k]!=arr[j][k]) chk=false;
            }
            if(chk) cnt++;
        }
    }
    cout<<cnt;
}