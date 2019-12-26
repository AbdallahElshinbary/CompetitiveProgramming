#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s;
	ll a,b;
	vector<ll> v;
	while(cin >> s) {
		sort(s.begin(), s.end());
		do {
			if(s[0] == '0') continue;
			v.push_back(stoll(s));
		} while(next_permutation(s.begin(), s.end()));
		sort(v.begin(), v.end());

		a = v[0], b = v.back();
		printf("%lld - %lld = %lld = 9 * %lld\n", b, a, b-a, (b-a)/9);
		v.clear();
	}

	return 0;
}
