#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    
    int mul = a * b * c;

    int arr[10] = {};

    while (mul != 0) {
        arr[mul % 10]++;
        mul /= 10;
    }
    for (int v : arr) {
        cout << v << "\n";
    }
    return 0;
}