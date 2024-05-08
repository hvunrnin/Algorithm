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
        int num;
        cin >> num;
        if (num == 0) {
            s.pop();
        }
        else {
            s.push(num);
        }
    }
    
    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum;

    return 0;
}