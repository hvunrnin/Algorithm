//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;
    int n, m;
    cin >> n >> m;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    while (m--) {
        int num;
        cin >> num;

        int index = find(dq.begin(), dq.end(), num) - dq.begin();

        while (num != dq.front()) {
            if (index < dq.size() - index) {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
        dq.pop_front();
    }

    cout << cnt;

    return 0;
}