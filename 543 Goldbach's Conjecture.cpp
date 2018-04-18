#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;
vector<bool> prime(MAX, true);
int freq[MAX]{};

void sieve(int n) {
	prime[0] = prime[1] = false;
	for(int i=2; i*i<=n; i++) {
		if(prime[i]) {
			for(int j=2*i; j<n; j+=i)
				prime[j] = false;
		}
	}
}


int main()
{
	int n, cnt{0};
	sieve(MAX);
	vector<int> primes;
	for(int i=0; i<MAX; i++) {
		if(prime[i])
			primes.push_back(i), cnt++;
		freq[i] = cnt;
	}

	while(cin >> n && n) {
		for(int x : primes) {
			if(x > n)
				break;
			if(prime[n-x]) {
				printf("%d = %d + %d\n", n, x, n-x);
				break;
			}
		}
	}


	return 0;
}

