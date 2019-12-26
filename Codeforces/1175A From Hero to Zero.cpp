#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll t,n,k,ans;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		ans = 0;
		while(n) {
			ans += n%k;
			n -= n%k;
			if(n) n /= k, ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}
