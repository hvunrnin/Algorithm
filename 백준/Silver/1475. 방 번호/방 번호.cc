#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num=0;
    int cnt=0;
    int arr[10] = {};
    cin >> num;
    while (num != 0) {
        arr[num % 10]++;
        num /= 10;
    }
    if ((arr[6] + arr[9]) % 2 == 1) {
        arr[6] = (arr[6] + arr[9]) / 2 + 1;
    }
    else {
        arr[6] = (arr[6] + arr[9]) / 2;
    }
    arr[9] = arr[6];
    for (int n : arr) {
        if (n > cnt) {
            cnt = n;
        }
    }
    cout << cnt;
    return 0;
}