#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll t,k,n,a,b;
	cin >> t;
	while(t--) {
		cin >> k >> n >> a >> b;

		if(b*n >= k) {cout << "-1\n"; continue;}

		ll s=0, e=n, m, x, y, ans=-1;
		while(s <= e) {
			m = (s+e)/2;
			x = k - m*a, y = n-m;
			if(b*y >= x) e = m-1;
			else ans=m, s = m + 1;
		}
		cout << ans << "\n";
	}


	return 0;
}







