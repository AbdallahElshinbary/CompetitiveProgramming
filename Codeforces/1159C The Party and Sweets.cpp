#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n,m,x,y,ans = 0;
	ll a[100005], b[100005];
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		ans += a[i]*m;
	}
	for(int i=0; i<m; i++) cin >> b[i];

	sort(a, a+n, greater<ll>());
	sort(b, b+m);
	x = a[0], y = b[0];

	if(x > y) {cout << -1; return 0;}

	for(int i=1; i<m; i++)
		ans -= x, ans += b[i];

	if(b[0] > a[0]) {
		if(n == 1) {cout << -1; return 0;}
		ans -= a[1], ans += b[0];
	}
	cout << ans;

	return 0;
}
