#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	string s;
	cin >> n;
	getline(cin, s);
	while(n--) {
		getline(cin, s);
		if(s.empty()) {
			cout << "Yes\n";
			continue;
		}

		stack<char> st;
		bool ok = true;
		for(char c : s) {
			if(c == ' ') continue;
			if(c == '(' || c == '[') st.push(c);
			else {
				if(!st.empty() && ((st.top() == '(' && c == ')') || (st.top() == '['&& c == ']'))) st.pop();
				else {
					ok = false;
					break;
				}
			}
		}
		if(!st.empty()) ok = false;
		cout << ((ok) ? "Yes\n" : "No\n");
	}

	return 0;
}
