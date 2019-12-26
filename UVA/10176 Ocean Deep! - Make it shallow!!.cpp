#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(int n, int p, int m) {
	ll curr=n, res=1;
	while(p) {
		if(p%2 == 1) {
			res *= curr;
			res %= m;
		}
		p /= 2;
		curr *= curr;
		curr %= m;
	}
	return res;
}

int main() {
	string s, n;
	while(cin >> s) {
		n += s;
		if(n.back() != '#') continue;
		n.pop_back();

		ll res=0, m=131071, x=n.size()-1;
		for(char c : n) {
			if(c == '1')
				res = (res%m + power(2, x, m)) % m;
			x--;
		}
		cout << (res == 0 ? "YES\n" : "NO\n");
		n = "";
	}

	return 0;
}

