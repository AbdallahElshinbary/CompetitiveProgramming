#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100000;
bool prime[MAX];
vector<int> primes;
map<int, int> freq;

void sieve() {
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i]) {
			for(int j=2*i; j<MAX; j+=i) prime[j]=false;
		}
	}
	for(int i=2; i<MAX; i++) if(prime[i]) primes.push_back(i);
}

void factorize(int n) {
	for(int x : primes) {
		if(x > n) break;
		while(n%x == 0) {
			freq[x]++;
			n /= x;
		}
	}
	if(n > 1) freq[n]++;
}

int main() {
	for(int i=2; i<MAX; i++) prime[i]=true;
	sieve();

	ll n,m,c,x;
	bool flag;
	while(cin >> n >> m) {
		freq.clear();
		factorize(m);
		flag = true;
		for(auto f : freq) {
			c = 0, x = f.first;
			while(true) {
				c += (n/x);
				x *= f.first;
				if(n/x == 0) break;
			}
			if(c < f.second) {flag=false; break;}
		}
		if(flag) printf("%lld divides %lld!\n", m, n);
		else printf("%lld does not divide %lld!\n", m, n);
	}

	return 0;
}
