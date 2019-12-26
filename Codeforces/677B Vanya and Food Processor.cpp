#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n,h,k,x,r=0,ans=0;
	cin >> n >> h >> k;
	while(n--) {
		cin >> x;
		if(r+x > h) ans++, r=0;
		r += x;
		ans += r/k, r %= k;
	}
	if(r) ans++;
	cout << ans;

	return 0;
}
