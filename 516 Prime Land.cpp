#include <bits/stdc++.h>

using namespace std;

const int MAX = 32769;
vector<bool> prime(MAX, true);

void sieve(int n) {
	prime[0] = prime[1] = false;
	for(int i=2; i*i<=n; i++) {
		if(prime[i]) {
			for(int j=2*i; j<n; j+=i)
				prime[j] = false;
		}
	}
}

int main()
{
	string s;
	int n,m,x;
	map<int, int> mp;
	vector<int> primes;
	for(int i=2; i<MAX; i++)
		if(prime[i])
			primes.push_back(i);

	while(getline(cin, s) && s != "0") {
		stringstream ss(s);
		x = 1;
		while(ss >> n >> m)
			x *= pow(n,m);
		x--;
		for(int c : primes) {
			while(x%c == 0) {
				x /= c;
				mp[c]++;
			}
		}
		auto it = mp.end();
		it--;
		for(;; it--) {
			if(it == mp.begin()) break;
			printf("%d %d ", it->first, it->second);
		}
		printf("%d %d", it->first, it->second);
		cout << endl;
		mp.clear();
	}

	return 0;
}



