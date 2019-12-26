#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100000;
bool prime[MAX];

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
	int t,n,k,x,L,T;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &k);
		L = power(n, k, 1000);
		x = (log10(n)*k + 1) - 3;
		if(x <= 0) T = pow(n, k)/1000;
		else T = pow(10, k*log10(n) - x);
		printf("%03d...%03d\n", T, L);
	}

	return 0;
}
