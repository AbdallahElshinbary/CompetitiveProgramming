#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	int arr[200005];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);

	int ans=0, x;
	for(int i=0; i<n; i++) {
		x = lower_bound(arr, arr+n, arr[i]+6) - arr - i;
		ans = max(ans, x);
	}
	cout << ans;

	return 0;
}
