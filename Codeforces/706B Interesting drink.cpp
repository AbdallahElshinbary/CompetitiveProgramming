#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,q,x;
	int arr[100005];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);

	cin >> q;
	while(q--) {
		cin >> x;
		cout << (upper_bound(arr, arr+n, x) - arr) << "\n";
	}

	return 0;
}

