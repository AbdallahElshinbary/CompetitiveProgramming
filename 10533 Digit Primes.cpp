#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;
vector<bool> prime(MAX, true);
int freq[MAX]{};

void sieve(int n) {
	prime[0] = prime[1] = false;
	for(int i=2; i*i<=n; i++) {
		if(prime[i]) {
			for(int j=2*i; j<n; j+=i)
				prime[j] = false;
		}
	}
}

int sum(int n) {
	int s = 0;
	while(n)
		s+= n%10, n /= 10;
	return s;
}

int main()
{
	int n,t1,t2,cnt{0};
	cin >> n;
	sieve(MAX);
	for(int i=0; i<MAX; i++) {
		if(prime[i] && prime[sum(i)])
			cnt++;
		freq[i] = cnt;
	}


	while(n--) {
		cin >> t1 >> t2;
		cout << freq[t2]-freq[t1-1] << "\n";
	}


	return 0;
}

