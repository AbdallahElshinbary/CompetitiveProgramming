#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v;

vector<bool> prime(100005, true);
vector<int> primes;

void sieve(int n) {
	prime[0] = prime[1] = false;
	for(int i=2; i*i <= n; i++) {
		if(prime[i]) {
			for(int j=i*2; j<n; j+=i)
				prime[j] = false;
		}
	}
	for(int i=2; i<=n; i++)
		if(prime[i])
			primes.push_back(i);
}

void primeFactors(ll n) {
	for(int i : primes) {
		if(i*i > n) break;
		while(n%i == 0)
				v.push_back(i), n/=i;
	}
	if(n != 1)
		v.push_back(n);
}

int main()
{
	ll n;
	sieve(100000);
	while(cin >> n && n != -1) {
		primeFactors(n);
		for(ll x : v)
			cout << "    " << x << endl;
		cout << endl;
		v.clear();
	}

	return 0;
}



