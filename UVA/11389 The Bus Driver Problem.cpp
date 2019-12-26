#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int mo[100005], ev[100005];

int main() {
	int n,d,r,x;
	while(cin >> n >> d >> r && n) {
		for(int i=0; i<n; i++) cin >> mo[i];
		for(int i=0; i<n; i++) cin >> ev[i];

		sort(mo, mo+n);
		sort(ev, ev+n, greater<int>());

		ll ans = 0;
		for(int i=0; i<n; i++) {
			x = mo[i]+ev[i];
			if(x > d) ans += (r*(x-d));
		}
		cout << ans << "\n";
	}

	return 0;
}
