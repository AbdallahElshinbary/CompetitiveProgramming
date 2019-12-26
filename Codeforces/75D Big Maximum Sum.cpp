#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll best[55]{}, start[55]{}, end[55]{}, tot[55]{};

	int n,m,l[55],big[250005];
	int arr[55][5005];

	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> l[i];
		for(int j=0; j<l[i]; j++) cin >> arr[i][j];
	}

	for(int i=0; i<m; i++) cin >> big[i];

	int sum, mx;
	for(int i=1; i<=n; i++) {
		sum=0; mx=-1e9;

		for(int j=0; j<l[i]; j++) {
			tot[i] += arr[i][j];
			start[i] = max(start[i], tot[i]);
			sum += arr[i][j];
			mx = max(mx, sum);
			if(sum < 0) sum = 0;
		}
		best[i] = mx;
		end[i] = sum;
	}


	ll ans = -1e18, cur=0;
	for(int i=0; i<m; i++) {
		ans = max(ans, best[big[i]]);
		if(cur) ans = max(ans, cur+start[big[i]]);
		cur = max(0LL, max(end[big[i]], cur+tot[big[i]]));
	}

	cout << ans;

	return 0;
}





























