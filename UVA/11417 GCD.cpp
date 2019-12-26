#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, ans;
	while(scanf("%lld", &n) && n) {
		ans = 0;
		for(int i=1; i<n; i++)
			for(int j=i+1; j<=n; j++)
				ans += __gcd(i, j);
		printf("%lld\n", ans);
	}

	return 0;
}
