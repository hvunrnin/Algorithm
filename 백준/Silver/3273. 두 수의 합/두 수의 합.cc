//#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    int arr[100001] = {};
    bool check[2000001];
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    int goal;
    cin >> goal;
    int cnt=0;
    /*
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (arr[j] + arr[i] == goal) {
                cnt++;
            }
        }
    }
    */
    for (int i = 0; i < num; i++) {
        if (goal - arr[i] > 0 && check[goal - arr[i]]) {
            cnt++;
        }
        check[arr[i]] = true;
    }
    cout << cnt;
    return 0;
}