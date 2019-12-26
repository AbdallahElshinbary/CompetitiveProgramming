#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(int b, int p, int m) {
	ll curr=b, res=1;
	while(p) {
		if(p%2 == 1) {
			res *= curr;
			res %= m;
		}
		p /= 2;
		curr *= curr;
		curr %= m;
	}
	return res;
}

int main() {
	int b,p,m;
	while(cin >> b >> p >> m) cout << power(b, p, m) << "\n";

	return 0;
}

