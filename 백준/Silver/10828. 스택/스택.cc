//#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int n;
    cin >> n;
    while (n--) {
        string c;
        cin >> c;

        if (c == "push") {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (c == "pop") {
            if (!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (c == "size") {
            cout << s.size() << '\n';
        }
        else if (c == "empty") {
            if (s.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            if (s.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << s.top() << '\n';
            }
        }

    }

    return 0;
}