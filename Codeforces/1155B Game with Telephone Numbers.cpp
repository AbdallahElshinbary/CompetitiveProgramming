#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, m, x;
	string s;
	cin >> n >> s;
	m = n-11;
	x = ceil(m*1.0/2);

	for(int i=0; i<n; i++) {
		if(x == 0) break;
		if(s[i] != '8') s[i]='x', x--;
	}

	x = m/2;
	for(int i=0; i<n; i++) {
		if(x == 0) break;
		if(s[i] == '8') s[i] = 'x', x--;
	}

	for(int i=0; i<n; i++) {
		if(s[i] == 'x') continue;
		if(s[i] == '8') {cout << "YES"; break;}
		else {cout << "NO"; break;}
	}

	return 0;
}
































