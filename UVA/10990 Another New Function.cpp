#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX=2000005;
bool prime[MAX];
vector<int> primes;
ll phi[MAX], dphi[MAX];

void sieve() {
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=i*2; j<MAX; j+=i) prime[j]=false;
	}
	for(int i=2; i<MAX; i++) if(prime[i]) primes.push_back(i);
}

int cal(int n) {
	if(phi[n] == 1) return (dphi[n] = 1);
	return (dphi[n] = 1 + cal(phi[n]));
}

int main() {
	fill(prime+2, prime+MAX, true);
	sieve();

	for(int i=2; i<MAX; i++) phi[i]=i;

	for(int i : primes)
		for(int j=i; j<MAX; j+=i)
			if(j%i == 0) phi[j] -= phi[j]/i;

	for(int i=3; i<MAX; i++) if(!dphi[i]) cal(i);
	for(int i=3; i<MAX; i++) dphi[i] += dphi[i-1];

	int t,m,n;
	cin >> t;
	while(t--) {
		cin >> m >> n;
		cout << dphi[n]-dphi[m-1] << "\n";
	}

	return 0;
}
