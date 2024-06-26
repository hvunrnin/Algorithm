//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int>> dq;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        while (!dq.empty() && dq.back().second >= num) {
            dq.pop_back();
        }

        dq.push_back({ i, num });

        if (dq.front().first <= i - L) {
            dq.pop_front();
        }

        cout << dq.front().second << " ";
    }


    return 0;
}