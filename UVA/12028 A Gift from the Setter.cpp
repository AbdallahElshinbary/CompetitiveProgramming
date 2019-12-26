#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll t,k,c,x,n;
	ll a[100005];
	ll pre[100005];
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> k >> c >> n >> x;

		a[0] = x;
		for(int i=1; i<n; i++) {
			a[i] = (k * a[i-1] + c) % 1000007;
		}
		sort(a, a+n);

		pre[0] = a[0];
		for(int i=1; i<n; i++)
			pre[i] = a[i] + pre[i-1];

		ll ans = 0;
		for(int i=0; i<n; i++)
			ans += llabs((a[i]*(n-i-1)) - (pre[n-1]-pre[i]));
		printf("Case %d: %lld\n", T, ans);
	}

	return 0;
}

