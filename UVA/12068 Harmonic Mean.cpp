#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll t, n, x, y, g;
	ll arr[10];
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> n;
		x = 1, y=0;
		for(int i=0; i<n; i++) cin >> arr[i], x *= arr[i];
		for(int i=0; i<n; i++) y += x/arr[i];
		x *= n;
		g = __gcd(x, y);
		x /= g, y /= g;
		printf("Case %d: %lld/%lld\n", T, x, y);
	}

	return 0;
}
