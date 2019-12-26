#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m;
	while(cin >> n >> m) {
		ll arr[m];
		for(int i=0; i<m; i++) cin >> arr[i];

		ll ans = n, num, x;

		for(int i=1; i<(1 << m); i++) {
			num = 0, x = 1;
			for(int j=0; j<m; j++) {
				if(i & (1 << j)) num++, x = (x*arr[j])/__gcd(x, arr[j]);
			}
			if(num%2 == 0) ans += n/x;
			else ans -= n/x;
		}
		cout << ans << "\n";
	}

	return 0;
}
