#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> prime(65005, true);

void sieve(int n) {
	prime[0] = prime[1] = false;
	for(int i=2; i*i <= n; i++) {
		if(prime[i]) {
			for(int j=i*2; j<n; j+=i)
				prime[j] = false;
		}
	}
}

ll POW(ll b, ll p, ll m) {
	if(p == 0)
		return 1;

	ll sq = POW(b, p/2, m);
	sq = ((sq%m)*(sq%m))%m;

	if(p%2 != 0)
		sq = ((sq%m)*(b%m))%m;

	return sq;
}

int main()
{
	int n;
	sieve(65002);
	while(cin >> n && n) {
		if(!prime[n] && POW(2, n, n) == 2 && POW(3, n, n) == 3 && POW(5, n, n) == 5)
			printf("The number %d is a Carmichael number.\n", n);
		else
			printf("%d is normal.\n", n);
	}

	return 0;
}



