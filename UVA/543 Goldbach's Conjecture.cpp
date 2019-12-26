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

	for(int i=2; i<MAX; i++) {
		if(prime[i]) primes.push_back(i);
	}
}

int main() {
	for(int i=0; i<MAX; i++) prime[i]=true;
	sieve();

	int n;
	while(cin >> n && n) {
		for(int x : primes) {
			if(prime[n-x]) {
				printf("%d = %d + %d\n", n, x, n-x);
				break;
			}
		}
	}

	return 0;
}
