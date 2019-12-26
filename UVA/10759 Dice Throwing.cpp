#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[30][160];
ll n, x, a, b, g;

ll solve(int n, int sum) {
	ll &ret = dp[n][sum];
	if(ret != -1) return ret;

	if(n == 0) return ret = (sum >= x);

	ret = 0;
	for(int i=1; i<=6; i++)
		ret += solve(n-1, sum+i);

	return ret;
}


int main() {
	while(cin >> n >> x && n) {
		memset(dp, -1, sizeof dp);
		a = solve(n, 0);
		b = powl(6, n);
		g = __gcd(a, b);
		a/=g, b/=g;
		if(b != 1) cout << a << "/" << b << "\n";
		else cout << a << "\n";
	}

	return 0;
}
