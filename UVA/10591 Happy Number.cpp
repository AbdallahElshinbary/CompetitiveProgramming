#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sum(ll n) {
	ll x, res = 0;
	while(n) {
		x = n%10, n /= 10;
		res += x*x;
	}
	return res;
}

int main() {
	ll t, n, x;
	string ans;
	map<int, int> freq;
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> n;
		x = n;
		bool flag = false;
		freq.clear();
		do {
			x = sum(x);
			if(x == 1) {flag = true; break;}
			freq[x]++;
			if(freq[x] == 5) break;
		} while(x != n);

		ans = (flag ? "is a Happy number." : "is an Unhappy number.");
		printf("Case #%d: %lld %s\n", T, n, ans.c_str());
	}


	return 0;
}
