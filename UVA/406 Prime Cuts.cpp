#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
vector<bool> prime(MAX, true);
int freq[MAX]{};

void sieve(int n) {
	prime[0] = false;
	for(int i=2; i*i<=n; i++) {
		if(prime[i]) {
			for(int j=2*i; j<n; j+=i)
				prime[j] = false;
		}
	}
}


int main()
{
	int n, c, l, r, s, cnt{0};
	sieve(MAX);
	vector<int> primes;
	for(int i=0; i<MAX; i++) {
		if(prime[i])
			primes.push_back(i), cnt++;
		freq[i] = cnt;
	}

	while(cin >> n >> c) {
		s = freq[n]/2;
		r = c-1;
		if(freq[n]%2 == 0) l = c;
		else l = c-1;
		l = max(s-l, 0);
		r = min(s+r, freq[n]-1);
		cout << n << " " << c << ": ";
		for(int i=l; i< r; i++)
			cout << primes[i] << " ";
		cout << primes[r] << endl << endl;
	}


	return 0;
}

