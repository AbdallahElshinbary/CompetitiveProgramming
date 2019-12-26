#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<18> MASK;

int n,m,k,x,y;
int sat[20]{}, rule[20][20]{};
ll dp[1<<18][20];

ll solve(MASK mask, int last) {
	if((int)mask.count() == m) return 0;

	ll &ret = dp[mask.to_ulong()][last];
	if(last != -1 && ret != -1) return ret;
	ret = 0;

	for(int i=0; i<n; i++) {
		if(!mask[i]) {
			mask.set(i);
			ret = max(ret, sat[i] + (last != -1 ? rule[last][i] : 0) + solve(mask, i));
			mask.reset(i);
		}
	}

	return ret;
}

int main() {
	cin >> n >> m >> k;
	for(int i=0; i<n; i++) cin >> sat[i];
	for(int i=0; i<k; i++) cin >> x >> y >> rule[x-1][y-1];
	memset(dp, -1, sizeof dp);
	MASK mask;
	cout << solve(mask, -1);

	return 0;
}




























