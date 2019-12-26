#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100005;
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

bool isPrime(int n) {
	if(n < MAX) return prime[n];
	for(int x : primes)
		if(n%x == 0) return false;
	return true;
}

int main() {
	for(int i=0; i<MAX; i++) prime[i]=true;
	sieve();

	int n;
	ll x;
	bool prime1, prime2;
	while(cin >> n && n) {
		prime1 = isPrime(n), prime2 = isPrime(powl(2, n) - 1);
		if(prime1 && prime2) {
			x = powl(2, n-1)*(powl(2, n) - 1);
			printf("Perfect: %lld!\n", x);
		} else {
			if(prime1) printf("Given number is prime. But, NO perfect number is available.\n");
			else printf("Given number is NOT prime! NO perfect number is available.\n");
		}
	}

	return 0;
}
