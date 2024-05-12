#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int cnt = 0;
	while (N--) {
		string s;
		cin >> s;
		stack<char> st;
		for (auto c : s) {
			if (!st.empty() && st.top() == c) {
				st.pop();
			}
			else {
				st.push(c);
			}
		}
		if (st.empty()) {
			cnt++;
		}
	}
	cout << cnt;
}