//#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() != 1) {
        q.pop();
        int num = q.front();
        q.pop();
        q.push(num);
    }

    cout << q.front();

    return 0;
}