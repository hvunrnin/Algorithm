#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000];

int lowest(int target, int length){
    int st=0;
    int en=length;
    while(st<en){
        int mid=(st+en)/2;
        if(arr[mid]>=target) en=mid;
        else st=mid+1;
    }
    return st;
}

int uppest(int target, int length){
    int st=0;
    int en=length;
    while(st<en){
        int mid=(st+en)/2;
        if(arr[mid]>target) en=mid;
        else st=mid+1;
    }
    return st;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int m;
    cin>>m;
    while(m--){
        int num;
        cin>>num;
        cout<<uppest(num, n)-lowest(num,n)<<" ";
    }
    return 0;
}