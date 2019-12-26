#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100000;
bool prime[MAX];
vector<int> primes;

void sieve() {
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=i*2; j<MAX; j+=i) prime[j]=false;
	}
	for(int i=2; i<MAX; i++) if(prime[i]) primes.push_back(i);
}

int solve(int n) {
	int p, factors=1, phi=n;
	for(int i : primes) {
		if(i > n) break;
		p = 0;
		if(n%i == 0) {
			while(n%i == 0) n /= i, p++;
			factors *= (p+1);
			phi -= phi/i;
		}
	}
	if(n>1) factors *= 2, phi -= phi/n;
	return factors + phi - 1;
}

int main() {
	for(int i=2; i<MAX; i++) prime[i]=true;
	sieve();

	int n;
	while(cin >> n) cout << n - solve(n) << "\n";

	return 0;
}
