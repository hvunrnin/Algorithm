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

    string ans;

    int cnt = 1;
    
    while (n--) {
        int num;
        cin >> num;
        while (cnt <= num) {
            s.push(cnt++);
            ans += "+\n";
        }
        if (s.top()!=num) {
            cout << "NO\n";
            return 0;
        }
        s.pop();
        ans += "-\n";
    }
    cout << ans;
    return 0;
}