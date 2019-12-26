#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<10> MASK;

const int MOD = 1000000007;
int mxn = 10, mxm = 100;
int dp[1<<10][10][105][105];
int ans[11][105];

ll go(int base, MASK mask, int idx, int last, int len) {
	mask.set(last);
	if(idx == len) {
		return (int)mask.count() == base;
	}

	int &ret = dp[mask.to_ulong()][last][idx][len];
	if(ret != -1) return ret;
	ret = 0;



	if(last == 0) {ret += go(base, mask, idx+1, 1, len); ret %= MOD;}
	else if(last == base-1) {ret += go(base, mask, idx+1, base-2, len); ret %= MOD;}
	else {
		ret += go(base, mask, idx+1, last+1, len); ret %= MOD;
		ret += go(base, mask, idx+1, last-1, len); ret %= MOD;
	}

	return ret % MOD;
}

int main() {
	MASK mask;
	ll x = 0;
	for(int i=2; i<=10; i++) {
		memset(dp, -1, sizeof dp);
		for(int j=i; j<=100; j++) {
			x = 0;
			for(int k=1; k<i; k++)
				x = (x%MOD + go(i, mask, 1, k, j)%MOD) % MOD;
			ans[i][j] = x;
			ans[i][j] = (ans[i][j]%MOD + ans[i][j-1]%MOD) % MOD;
		}
	}

	int t,n,m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		cout << ans[n][m] << "\n";
	}

	return 0;
}
