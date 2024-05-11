#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		string s;
		getline(cin, s);
		if (s == ".") {
			break;
		}
		stack<char> st;
		bool balance = true;
		for (auto c : s) {
			if (c == '(' || c == '[') {
				st.push(c);
			}
			else if (c == ')') {
				if (st.empty() || st.top() != '(') {
					balance = false;
					break;
				}
				st.pop();
			}
			else if (c == ']') {
				if (st.empty() || st.top() != '[') {
					balance = false;
					break;
				}
				st.pop();
			}
		}
		if (!st.empty()) {
			balance = false;
		}
		if (balance) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
}