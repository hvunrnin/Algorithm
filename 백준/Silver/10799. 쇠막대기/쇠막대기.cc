#include <iostream>
#include <string>
#include <stack>
typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll cnt = 0;
	string s;
	cin >> s;
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			if (s[i-1] == '(') {
				st.pop();
				cnt += st.size();
			}
			else {
				st.pop();
				cnt++;
			}
		}
	}
	cout << cnt;
}