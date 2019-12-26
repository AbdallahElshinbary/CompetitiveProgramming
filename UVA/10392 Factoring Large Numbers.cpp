#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> factors;

void factorize(ll n) {
	for(ll i=2; i*i<=n; i++) {
		while(n%i == 0) {
			n /= i;
			factors.push_back(i);
		}
	}
	if(n) factors.push_back(n);
}

int main() {
	ll n;
	while(cin >> n && n > 0) {
		factors.clear();
		factorize(n);
		for(ll x : factors) cout << "    " << x << "\n";
		cout << "\n";
	}

	return 0;
}
