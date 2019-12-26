#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,n,k,x,d,bd,ans;
	int arr[200005];

	cin >> t;
	while(t--) {
		cin >> n >> k;
		bd = 1e9+5;

		for(int i=0; i<n; i++) cin >> arr[i];
		for(int i=0; i<n-k; i++) {
			x = (arr[i]+arr[i+k])/2;
			d = max(x-arr[i], arr[i+k]-x);
			if(d < bd)
				bd = d, ans = x;
		}
		cout << ans << "\n";
	}


	return 0;
}
