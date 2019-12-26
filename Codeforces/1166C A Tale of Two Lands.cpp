#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n,s,x,y,z,ans=0;
	int arr[200005];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);

	s = lower_bound(arr, arr+n, 0) - arr;

	for(int i=s; i<n; i++) {
		x = lower_bound(arr, arr+n, 2*arr[i]) - arr;
		if(x == n || arr[x] > 2*arr[i]) x--;
		ans += x-i;
	}

	for(int i=0; i<s; i++) {
		x = lower_bound(arr, arr+n, 2*arr[i]) - arr;
		y = lower_bound(arr, arr+n, -2*arr[i]) - arr;
		z = lower_bound(arr, arr+n, ceil(arr[i]*-1.0/2)) - arr;

		if(y == n || arr[y] > -2*arr[i]) y--;

		ans += i-x;
		ans += y-z+1;
	}

	cout << ans;

	return 0;
}
