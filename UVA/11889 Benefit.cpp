#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll t, a, c, ans;
	vector<ll> facts;
	cin >> t;
	while(t--) {
		cin >> a >> c;
		for(int i=2; i*i<=c; i++)
			if(c%i == 0) facts.push_back(i), facts.push_back(c/i);
		facts.push_back(1), facts.push_back(c);

		ans = -1;
		sort(facts.begin(), facts.end());
		for(ll b : facts)
			if(a*b/__gcd(a, b) == c) {ans = b; break;}

		if(ans == -1) printf("NO SOLUTION\n");
		else printf("%d\n", ans);
		facts.clear();
	}

	return 0;
}
