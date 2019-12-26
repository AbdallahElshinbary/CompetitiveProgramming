#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000005;
bool prime[MAX];
vector<int> primes;

void sieve() {
	prime[0] = prime[1] = false;
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=2*i; j<MAX; j+=i) prime[j]=false;
	}

	for(int i=2; i<MAX; i++) {
		if(prime[i]) primes.push_back(i);
	}
}

int main() {
	for(int i=0; i<MAX; i++) prime[i]=true;
	sieve();

	int t,a,b,x,y;
	map<int, int> freq;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		if(b < 2) {cout << "No jumping champion\n"; continue;}
		x = lower_bound(primes.begin(), primes.end(), a) - primes.begin();
		y = lower_bound(primes.begin(), primes.end(), b) - primes.begin();
		if(primes[y] != b) y--;
		if(x >= y) {cout << "No jumping champion\n"; continue;}

		for(int i=x; i<y; i++) freq[primes[i+1]-primes[i]]++;

		int mx = 0, ans, count=0;
		for(auto m : freq) {
			if(mx < m.second) mx=m.second, ans=m.first;
		}
		for(auto m : freq) if(m.second == mx) count++;

		if(count > 1) cout << "No jumping champion\n";
		else cout << "The jumping champion is " << ans << "\n";

		freq.clear();
	}

	return 0;
}
