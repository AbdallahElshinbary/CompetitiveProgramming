#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000005;
bool prime[MAX];
int mu[MAX], M[MAX];

void sieve() {
	for(int i=1; i<MAX; i++) prime[i]=true, mu[i] = 1;
	for(int i=2; i<MAX; i++) {
		if(prime[i]) {
			mu[i] = -1;
			for(int j=i*2; j<MAX; j+=i) {
				prime[j]=false;
				mu[j] = (j%(i*i) == 0 ? 0 : -mu[j]);
			}
		}
	}
}

int main() {
	sieve();
	int n, m = 0;
	for(int i=1; i<MAX; i++)
		m += mu[i], M[i] = m;
	
	while(cin >> n && n)
		printf("%8d%8d%8d\n", n, mu[n], M[n]);
	
	return 0;
}
