#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX=100005;
bool prime[MAX];
vector<int> primes;
ll numDiv[MAX], sumDiv[MAX];

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

	fill(numDiv, numDiv+MAX, 1);
	fill(sumDiv, sumDiv+MAX, 1);

	int x, p;
	for(int i : primes) {
		for(int j=i; j<MAX; j+=i) {
			x = j, p = 0;
			while(x%i == 0) x /= i, p++;
			numDiv[j] *= (p+1);
			sumDiv[j] *= ((ll)pow((double)i, p+1)-1)/(i-1);
		}
	}

	ll t,a,b,k,d,o;
	cin >> t;
	while(t--) {
		cin >> a >> b >> k;
		d = o = 0;
		for(int i=a; i<=b; i++)
			if(i%k == 0) d += numDiv[i], o += sumDiv[i];
		cout << d << " " << o << "\n";
	}

	return 0;
}
