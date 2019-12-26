#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX=1000005;
bool prime[MAX];
vector<int> primes;
int facts[MAX], ans[MAX];

void sieve() {
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=i*2; j<MAX; j+=i) prime[j]=false;
	}
	for(int i=2; i<MAX; i++) if(prime[i]) primes.push_back(i);
}

int main() {
	fill(prime+2, prime+MAX, true);
	sieve();

	fill(facts, facts+MAX, 1);

	int x, p;
	for(int i : primes) {
		for(int j=i*2; j<MAX; j+=i) {
			x = j, p=0;
			while(x%i == 0) x/=i, p++;
			facts[j] *= p+1;
		}
	}

	int mx=0, a;
	for(int i=2; i<MAX; i++) {
		x = facts[i];
		if(x >= mx) mx = x, a=i;
		ans[i]=a;
	}
	ans[1] = 1;

	int t,n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << ans[n] << "\n";
	}

	return 0;
}
