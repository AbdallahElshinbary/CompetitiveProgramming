#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> factors;

void factorize(ll n) {
	for(ll i=2; i*i<=n; i++) {
		if(n%i == 0) {
			factors.push_back(i);
			while(n%i == 0) n /= i;
		}
	}
	if(n > 1) factors.push_back(n);
}

int main() {
	ll n;
	while(cin >> n && n) {
		n = llabs(n);
		factors.clear();
		factorize(n);
		if(factors.size() <= 1) cout << "-1\n";
		else cout << factors.back() << "\n";
	}

	return 0;
}
