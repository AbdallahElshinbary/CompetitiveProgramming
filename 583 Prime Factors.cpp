#include <bits/stdc++.h>

using namespace std;

vector<int> v;

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

void primeFactors(int n) {
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
	int n;
	sieve(100000);
	while(cin >> n && n) {
		primeFactors(abs(n));
		printf("%d = ", n);
		if(n < 0) printf("-1 x ");
		for(int i=0; i<int(v.size())-1; i++)
			printf("%d x ", v[i]);;
		printf("%d\n", v[v.size()-1]);
		v.clear();
	}

	return 0;
}



