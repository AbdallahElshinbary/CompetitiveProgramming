#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[100005];

int main() {
	int n;
	while(cin >> n && n) {
		for(int i=0; i<n; i++) cin >> arr[i];
		ll ans = 0;
		for(int i=0; i<n-1; i++) {
			if(arr[i] > 0) ans += arr[i], arr[i+1] += arr[i];
			else if(arr[i] < 0) ans += abs(arr[i]), arr[i+1] += arr[i];
		}
		cout << ans << endl;
	}

	return 0;
}
