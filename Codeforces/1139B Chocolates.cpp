#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, cur, ans=0;
	int arr[200005];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];

	cur = arr[n-1]+1;
	for(int i=n-1; i>=0; i--) {
		arr[i] = min(arr[i], max((int) cur-1, 0));
		cur = arr[i], ans += arr[i];
	}
	cout << ans;

	return 0;
}
