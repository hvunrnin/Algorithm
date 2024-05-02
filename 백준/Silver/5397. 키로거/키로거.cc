//#include <bits/stdc++.h>
#include <iostream>
#include <list>


using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        string str;
        cin >> str;
        list<char> L;
        auto cursor = L.end();
        for (auto c : str) {
            if (c == '<') {
                if (cursor != L.begin()) {
                    cursor--;
                }
            }
            else if (c == '>') {
                if (cursor != L.end()) {
                    cursor++;
                }
            }
            else if (c == '-') {
                if (cursor != L.begin()) {
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
            else {
                L.insert(cursor, c);
            }
        }
        for (auto a : L) {
            cout << a;
        }
        cout << '\n';
    }
    return 0;
}