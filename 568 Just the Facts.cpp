#include <bits/stdc++.h>

using namespace std;

vector<bool> prime(100005, true);
vector<int> primes;
vector<pair<int, int> > factors;

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
		if(res != 0) factors.push_back({p, res});
	}
}

int POW(int b, int p, int m) {
	if(p == 0) return 1;

	int sq = POW(b, p/2, m);
	sq = ((sq%m)*(sq%m))%m;

	if(p%2 != 0)
		sq = ((sq%m)*(b%m))%m;

	return sq;
}

int fac(int n) {
	if(n <= 1) return 1;
	return n * fac(n-1);
}

int main()
{
	int n, tens, m, ans;
	sieve(100000);
	while(cin >> n) {
		ans = 1;
			tens = pow_num(n, 5);
			m = tens*10;
		if(m != 0) {
			factorize(n);

			for(auto x : factors) {
				if(x.first == 5) continue;
				if(x.first == 2) x.second -= tens;
				ans = ((ans%m)*(POW(x.first, x.second, m)))%m;
			}
		} else {
			ans = fac(n)%10;
		}
		cout << setw(5) << n << " -> " << ans%10 << endl;
		factors.clear();
	}
	return 0;
}



