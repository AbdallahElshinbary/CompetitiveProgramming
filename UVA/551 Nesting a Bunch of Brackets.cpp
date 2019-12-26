#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s;
	while(getline(cin, s)) {
		int pos = 0;
		while((pos = s.find("(*", pos)) != -1) {
			s.replace(pos, 2, "@");
			pos++;
		}
		pos = 0;
		while((pos = s.find("*)", pos)) != -1) {
			s.replace(pos, 2, "#");
			pos++;
		}

		stack<char> st;
		char c;
		bool ok = true;
		for(int i=0; i<(int)s.size(); i++) {
			c = s[i];
			if(st.empty() && (c == ')' || c == ']' || c == '}' || c == '>' || c == '#')) {
				cout << "NO " << i+1 << "\n"; ok=false; break;
			}
			if(c == ')') {
				if(st.top() == '(') st.pop();
				else {cout << "NO " << i+1 << "\n"; ok=false; break;}
			}
			if(c == ']') {
				if(st.top() == '[') st.pop();
				else {cout << "NO " << i+1 << "\n"; ok=false; break;}
			}
			if(c == '}') {
				if(st.top() == '{') st.pop();
				else {cout << "NO " << i+1 << "\n"; ok=false; break;}
			}
			if(c == '>') {
				if(st.top() == '<') st.pop();
				else {cout << "NO " << i+1 << "\n"; ok=false; break;}
			}
			if(c == '#') {
				if(st.top() == '@') st.pop();
				else {cout << "NO " << i+1 << "\n"; ok=false; break;}
			}
			if(c == '(' || c == '[' || c == '{' || c == '<' || c == '@') st.push(c);
		}
		if(ok && !st.empty()) {
			ok = false;
			cout << "NO " << s.size()+1 << "\n";
		}
		if(ok) cout << "YES\n";
	}
	return 0;
}
