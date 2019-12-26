#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000009

ll power(ll n, ll p){
	ll cur, res;
	cur = n;
	res = 1;
	while(p){
		if(p%2 == 1){
			res *= cur;
			res %= MOD;
		}
		p /= 2;
		cur *= cur;
		cur %= MOD;
	}
	return res;
}

int main() {
	ll n,m,k,x,e;
	cin >> n >> m >> k;

	x = n/k, e = n-m;

	if(e >= x) {
		cout << m;
	} else {
		x -= e;
		ll ans = m - x*k;
		ll y = power(2, x+1);
		y = (y-2+MOD)%MOD;
		y = (k*y)%MOD;
		ans = ((ans%MOD) + (y%MOD)) % MOD;
		cout << ans;
	}

	return 0;
}
