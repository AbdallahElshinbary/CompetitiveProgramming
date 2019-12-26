#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100005;
bool prime[MAX];
vector<ll> primes;

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

	int t, n, s, mx, ans;
	cin >> t;
	while(t--) {
		cin >> n;
		mx=0, ans=2;
		for(int x : primes) {
			if(x > n) break;
			s = n - (n/x)*x;
			if(s > mx) mx = s, ans=x;
		}
		cout << ans << "\n";
	}

	return 0;
}
