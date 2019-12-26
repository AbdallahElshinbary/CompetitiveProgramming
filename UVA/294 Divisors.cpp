#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100000;
bool prime[MAX];
vector<int> primes;

void sieve() {
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=2*i; j<MAX; j+=i) prime[j]=false;
	}
	for(int i=2; i<MAX; i++) if(prime[i]) primes.push_back(i);
}

int fact(int n) {
	int ans=1, p;
	for(int x : primes) {
		if(x > n) break;
		p = 0;
		while(n%x == 0) n/=x, p++;
		ans *= (p + 1);
	}
	if(n>1) ans *= 2;
	return ans;
}

int main() {
	for(int i=2; i<MAX; i++) prime[i]=true;
	sieve();

	int t,a,b,x,d,f;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		x = d = 0;
		for(int i=a; i<=b; i++) {
			f = fact(i);
			if(d < f) d=f, x=i;
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", a, b, x, d);
	}

	return 0;
}
