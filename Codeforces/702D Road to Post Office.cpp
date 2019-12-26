#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll d,k,a,b,t;
	cin >> d >> k >> a >> b >> t;

	ll ans = 0;
	if(d >= k) {d -= k, ans += a*k;}
	else {
		cout << min(a*d, b*d);
		return 0;
	}

	ll car = a*k+t, foot = b*k, intervals = d/k;
	if(intervals > 0) {
		ans += intervals*min(car, foot);
		d -= intervals*k;
	}

	ans += min(a*d+t, b*d);
	cout << ans;

	return 0;
}
