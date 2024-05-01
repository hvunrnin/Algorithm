//#include <bits/stdc++.h>
#include <iostream>
#include <list>


using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    list<char> L;
    for (auto c : str) {
        L.push_back(c);
    }
    
    auto cursor = L.end();
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        char op;
        cin >> op;

        if (op == 'P') {
            char ch;
            cin >> ch;
            L.insert(cursor, ch);
        }
        else if (op == 'L') {
            if (cursor != L.begin()) {
                cursor--;
            }
        }
        else if (op == 'D') {
            if (cursor != L.end()) {
                cursor++;
            }
        }
        else {
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for (auto c : L) {
        cout << c;
    }
    return 0;
}