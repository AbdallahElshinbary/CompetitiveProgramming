#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000005;
bool prime[MAX];
vector<int> digit_primes;
int query[MAX];

int sum(int n) {
	int x=0;
	while(n) {
		x += n%10;
		n/=10;
	}
	return x;
}

void sieve() {
	prime[0] = prime[1] = false;
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=2*i; j<MAX; j+=i) prime[j]=false;
	}

	for(int i=2; i<MAX; i++) {
		if(prime[i] && prime[sum(i)]) digit_primes.push_back(i);
	}
}

int main() {
	for(int i=0; i<MAX; i++) prime[i]=true;
	sieve();

	int s = 0, n=0;
	for(int x : digit_primes) {
		for(int i=s; i<x; i++) {
			query[i]=n;
		}
		s=x, n++;
	}
	for(int i=s; i<MAX; i++) query[i]=n;

	int t,a,b,ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &a, &b);
		ans = query[b]-query[a];
		if(prime[a] && prime[sum(a)]) ans++;
		printf("%d\n", ans);
	}

	return 0;
}
