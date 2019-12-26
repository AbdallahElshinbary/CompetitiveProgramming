#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100;
bool prime[MAX];
vector<int> primes;

void sieve() {
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=2*i; j<MAX; j+=i) prime[j] = false;
	}
	for(int i=2; i<MAX; i++) if(prime[i]) primes.push_back(i);
}

int main() {
	for(int i=2; i<MAX; i++) prime[i]=true;
	sieve();

	int n, l, m, cnt;
	int freq[100];
	while(cin >> n && n) {
		memset(freq, 0, sizeof freq);
		for(int x : primes) {
			if(n/x == 0) break;
			l = m = x;
			while(true) {
				freq[x] += n/m;
				m *= x;
				if(n/m == 0) break;
			}
		}
		printf("%3d! =", n);
		cnt = 0;
		for(int x : primes) {
			printf("%3d", freq[x]);
			if(x == l) break;
			if(++cnt == 15) printf("\n      ");
		}
		printf("\n");
	}

	return 0;
}
