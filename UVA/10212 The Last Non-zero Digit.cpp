#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, m, x;
	string s;
	while(scanf("%lld %lld", &n, &m) != EOF) {
		x=1;
		for(ll i=n; i>n-m; i--) {
			x *= i;
			while(x%10 == 0) x /= 10;
			x %= 1000000000;
		}
		printf("%d\n", x%10);
	}

	return 0;
}
