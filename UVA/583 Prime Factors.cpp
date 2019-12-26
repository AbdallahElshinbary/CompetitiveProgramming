#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100000;
bool prime[MAX];
vector<int> primes, factors;

void sieve() {
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=2*i; j<MAX; j+=i) prime[j] = false;
	}
	for(int i=2; i<MAX; i++) if(prime[i]) primes.push_back(i);
}

void factorize(int n) {
	for(int i : primes) {
		if(i*i > n) break;
		while(n%i == 0) {
			factors.push_back(i);
			n /= i;
		}
	}
	if(n > 1) factors.push_back(n);
}

int main() {
	for(int i=2; i<MAX; i++) prime[i]=true;
	sieve();

	int n;
	while(cin >> n && n) {
		factors.clear();
		factorize(abs(n));
		cout << n << " = ";
		if(n > 0) {
			cout << factors[0];
			for(int i=1; i<(int)factors.size(); i++) cout << " x " << factors[i];
		} else {
			cout << "-1";
			for(int x : factors) cout << " x " << x;
		}
		cout << "\n";
	}

	return 0;
}
