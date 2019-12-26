#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	int arr[300005];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];

	int mn = 1e9, x;
	for(int i=0; i<n; i++) {
		x = max(i-0, n-i-1);
		mn = min(mn, arr[i]/x);
	}
	cout << mn;

	return 0;
}
