#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		stack<char> st;
		for (auto c : s) {
			if (c == '(') {
				st.push(c);
			}
			else {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					st.push(c);
					break;
				}
			}
		}
		if (st.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}