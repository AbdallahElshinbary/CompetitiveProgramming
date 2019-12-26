#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[15];
bitset<10000008> roulette;

ll power(ll n, ll p, ll MOD) {
	ll cur = n, res = 1;
	while(p) {
		if(p % 2 == 1) {
			res *= cur;
			res %= MOD;
		}
		p /= 2;
		cur *= cur;
		cur %= MOD;
	}
	return res%MOD;
}

ll p(ll x, ll k, ll MOD) {
	ll ans = 0;
	for(int i=0; i<=k; i++) {
		ans = ((ans%MOD)+ ((arr[i]%MOD * power(x, i, MOD))%MOD)) % MOD;
	}
	return ans;
}

int main() {
	ll n, m, k;
	while(cin >> n >> m && n) {
		cin >> k;
		for(int i=0; i<=k; i++) cin >> arr[i];

		for(ll i=0; i<=m; i++) {
			roulette.set(p(i, k, n+1));
		}
		cout << roulette.count() << "\n";
		roulette.reset();
	}

	return 0;
}
