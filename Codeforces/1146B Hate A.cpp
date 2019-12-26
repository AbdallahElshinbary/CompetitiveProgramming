#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s, x, ans;
	int sz;
	cin >> s;
	for(char c : s) {
		if(c == 'a') continue;
		x += c;
	}
	sz = (int)s.size();

	int n = (int)x.size(), m = n/2, f=0, mn=0;
	if(n%2 == 1) {cout << ":("; return 0;}

	for(int i=0; i<n/2; i++)
		if(x[i] != x[i+m]) {cout << ":("; return 0;}

	for(int i=sz-1; i>=0; i--) {
		if(s[i] == 'a') {
			mn = i+1;
			break;
		}
	}

	int i;
	for(i=0; i<(int)s.size(); i++) {
		if(f == m) break;
		ans += s[i];
		if(s[i] != 'a') f++;
	}

	for(;i<(int)s.size(); i++) {
		if(s[i] != 'a') break;
		ans += s[i];
	}

	if(mn > (int)ans.size()) {cout << ":("; return 0;}
	cout << ans;

	return 0;
}
