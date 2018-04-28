#include <bits/stdc++.h>

using namespace std;

vector<bool> prime(100005, true);
vector<int> primes;
vector<int> factors;

void sieve(int n) {
	prime[0] = prime[1] = false;
	for(int i=2; i*i<=n; i++) {
		if(prime[i]) {
			for(int j=i*2; j<=n; j+=i)
				prime[j] = false;
		}
	}

	for(int i=2; i<=n; i++)
		if(prime[i])
			primes.push_back(i);
}


int pow_num(int n, int p) {
	int ans = 0;
	for(int i=p; i<=n; i*=p)
		ans += n/i;
	return ans;
}

void factorize(int n) {
	int res;
	for(int p : primes) {
		if(p > n) break;
		res = pow_num(n, p);
		factors.push_back(res);
	}
}

int main()
{
	int n, f;
	sieve(100000);
	while(cin >> n && n) {
		factorize(n);
		f = 0;
		cout << setw(3) << n << "! =";
		for(int x : factors) {
			if(f == 15) {
				cout << "\n      ";
				f = 0;
			}
			cout << setw(3) << x;
			f++;
		}
		cout << endl;
		factors.clear();
	}
	return 0;
}



