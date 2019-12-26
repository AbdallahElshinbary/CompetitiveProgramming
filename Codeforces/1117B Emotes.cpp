#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
//	int n;
//	cin >> n;
//	int arr[n];
//	for(int i=0; i<n; i++) cin >> arr[i];

	int n,m,k;
	cin >> n >> m >> k;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n, greater<int>());

	ll x = arr[0], y = arr[1];
	ll z = (k*x + y);
	ll ans = (m/(k+1))*z;
	ans += (m%(k+1))*x;
	cout << ans;

	return 0;
}
