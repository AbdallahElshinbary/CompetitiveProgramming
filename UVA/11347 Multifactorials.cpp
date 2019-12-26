#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

map<int, int> mp;

void factorize(int n) {
	for(int i=2; i*i<=n; i++)
		while(n%i == 0) n/=i, mp[i]++;
	if(n > 1) mp[n]++;
}

int main() {
	int t, n, x;
	string s;
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> n >> s;
		x = (int) s.size();
		while(n > 0) {
			factorize(n);
			n -= x;
		}

		ull ans = 1;
		for(auto m : mp) {
			ans *= m.second+1;
			if(ans > 1e18) break;
		}

		printf("Case %d: ", T);
		if(ans > 1e18) printf("Infinity\n");
		else printf("%lld\n", ans);
		mp.clear();
	}

	return 0;
}
