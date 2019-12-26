#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 5e18

ll n, x[3], a[100005];
ll dp[100005][3];

ll go(int idx, int t) {
	if(t == 3) return 0;
	if(idx == n) return -INF;

	ll &ret = dp[idx][t];
	if(ret != -INF) return ret;
	return ret = max(x[t]*a[idx] + go(idx, t+1), go(idx+1, t));
}

int main() {
	cin >> n >> x[0] >> x[1] >> x[2];
	for(int i=0; i<n; i++) cin >> a[i];

	for(int i=0; i<100005; i++)
		for(int j=0; j<3; j++)
			dp[i][j] = -INF;
	cout << go(0, 0);

	return 0;
}
