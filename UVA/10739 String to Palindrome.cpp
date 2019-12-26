#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int dp[1005][1005];

int go(int l, int r) {
	if(l > r) return 0;

	int &ret = dp[l][r];
	if(ret != -1) return ret;

	if(s[l] == s[r]) return ret = go(l+1, r-1);

	int o1 = 1 + go(l, r-1);
	int o2 = 1 + go(l+1, r);
	int o3 = 1 + go(l+1, r-1);

	return ret = min(o1, min(o2, o3));
}


int main() {
	int t;
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> s;
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", T, go(0,s.size()-1));
	}

	return 0;
}
