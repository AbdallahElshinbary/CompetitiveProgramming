#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll h,n,x,y,z;
	ll arr[200005], brr[200005];
	cin >> h >> n;
	x = h;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		x += arr[i];
		if(x <= 0) {cout << i+1; return 0;}
		brr[i] = x;
	}

	if(x >= h) {cout << -1; return 0;}

	ll ans = 1e18;

	for(int i=0; i<n; i++) {
		x += arr[i];
		if(x <= 0) {cout << n+i+1; return 0;}
		y = brr[i]-x;
		z = ceil(brr[i]*1.0/y);
		ans = min(ans, z*n +i+1);
	}
	cout << ans;

	return 0;
}
