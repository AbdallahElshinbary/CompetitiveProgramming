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

void sieve() {
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=2*i; j<MAX; j+=i) prime[j] = false;
	}
}

int main() {
	for(int i=2; i<MAX; i++) prime[i]=true;
	sieve();

	int n;
	bool flag;
	while(scanf("%d", &n) && n) {
		if(prime[n]) {printf("%d is normal.\n", n); continue;}
		flag = true;
		for(int i=2; i<n; i++)
			if(power(i, n, n) != i) {flag=false; break;}
		if(flag) printf("The number %d is a Carmichael number.\n", n);
		else printf("%d is normal.\n", n);
	}

	return 0;
}
