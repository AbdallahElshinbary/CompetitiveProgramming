#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll n, ll p, ll m) {
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
	ll t,x,y,n;
	cin >> t;
	while(t--) {
		cin >> x >> y >> n;
		cout << power(x, y, n) << "\n";
	}

	return 0;
}