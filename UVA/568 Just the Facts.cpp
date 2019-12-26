#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, x;
	while(cin >> n) {
		x = 1;
		for(int i=2; i<=n; i++) {
			x = (x*i)%1000000000;
			while(x%10 == 0) x/=10;
		}
		printf("%5lld -> %d\n", n, x%10);
	}

	return 0;
}
