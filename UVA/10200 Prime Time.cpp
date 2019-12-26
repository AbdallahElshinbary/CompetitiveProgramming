#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100005;
bool prime[MAX];
vector<int> primes;

int euler_prime[10004];

void sieve() {
	prime[0] = prime[1] = false;
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=2*i; j<MAX; j+=i) prime[j]=false;
	}
	for(int i=0; i<MAX; i++)
		if(prime[i]) primes.push_back(i);
}

bool isPrime(int n) {
	if(n < MAX) return prime[n];
	for(int x : primes)
		if(n%x == 0) return false;
	return true;
}

int main() {
	for(int i=0; i<MAX; i++) prime[i]=true;
	sieve();

	int x, ep=0;
	for(int i=0; i<10002; i++) {
		x = i*i + i + 41;
		if(isPrime(x)) ep++;
		euler_prime[i] = ep;
	}

	int a,b,x1,x2,m;
	while(cin >> a >> b) {
		x1 = euler_prime[a];
		x2 = euler_prime[b];
		m = x2-x1;
		if(isPrime(a*a + a + 41)) m++;
		cout << fixed << setprecision(2) << (m*1.0)/(b-a+1)*100 + 0.00000000001 << "\n";
	}

	return 0;
}
