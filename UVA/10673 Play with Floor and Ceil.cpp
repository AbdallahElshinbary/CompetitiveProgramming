#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll extended_eculid(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1, y = 0;
		return a;
	}

	ll g = extended_eculid(b, a%b, y, x);
	y -= (a/b)*x;

	return g;
}

ll dioph(ll a, ll b, ll c, ll &x, ll &y) {
	ll g = extended_eculid(a, b, x, y);

	if(c%g == 0)
		x *= c/g, y *= c/g;

	return g;
}

int main() {
	ll t,x,k,n,m;
	cin >> t;
	while(t--) {
		cin >> x >> k;
		dioph(x/k, ceil(x*1.0/k), x, n, m);
		cout << n << " " << m << "\n";
	}

	return 0;
}
