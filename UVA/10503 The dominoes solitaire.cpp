#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<14> MASK;

int n,m,l1,r1,l2,r2;
int L[20], R[20];
int dp[1<<14][15][10][10];

bool go(MASK mask, int s, int l, int r) {
	if(s == 0) return l == r;

	int &ret = dp[mask.to_ulong()][s][l][r];
	if(ret != -1) return ret;
	ret = 0;

	MASK tmask = mask;
	for(int i=0; i<m; i++) {
		if(!tmask[i]) {
			if(L[i] == l) tmask.set(i), ret |= go(tmask, s-1, R[i], r);
			else if(R[i] == l) tmask.set(i), ret |= go(tmask, s-1, L[i], r);

			tmask = mask;
			if(L[i] == r) tmask.set(i), ret |= go(tmask, s-1, l, R[i]);
			else if(R[i] == r) tmask.set(i), ret |= go(tmask, s-1, l, L[i]);
		}
		if(ret) return ret;
	}

	return ret;
}

int main() {
	while(cin >> n && n) {
		cin >> m >> l1 >> r1 >> l2 >> r2;
		for(int i=0; i<m; i++) cin >> L[i] >> R[i];
		memset(dp, -1, sizeof dp);
		MASK mask;
		cout << (go(mask, n, r1, l2) ? "YES\n" : "NO\n");
	}
	return 0;
}
