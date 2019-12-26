#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000005;
bool prime[MAX];
vector<int> primes;

void sieve() {
	prime[0] = prime[1] = false;
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=2*i; j<MAX; j+=i) prime[j]=false;
	}
	for(int i=0; i<MAX; i++)
		if(prime[i]) primes.push_back(i);
}

int main() {
	for(int i=0; i<MAX; i++) prime[i]=true;
	sieve();

	ll t=1, n, pos, ans;
	while(cin >> n && n) {
		ans = 0;
		for(int x : primes) {
			if(x > n) break;
			if(n-x >= x) {
				pos = lower_bound(primes.begin(), primes.end(), x) - primes.begin() - 1;
			} else {
				pos = lower_bound(primes.begin(), primes.end(), n-x) - primes.begin();
				if(primes[pos] > n-x) pos--;
			}
			ans += pos+1;
		}
		printf("Case %lld: %lld\n", t++, ans);
	}

	return 0;
}
