#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s,ans;
int dp[1005][1005];

int go(int l, int r) {
	if(l > r) return 0;

	int &ret = dp[l][r];
	if(ret != -1) return ret;

	if(s[l] == s[r])
		return ret = go(l+1, r-1);

	int o1 = 1 + go(l, r-1);
	int o2 = 1 + go(l+1, r);

	return ret = min(o1, o2);
}

void trace(int l, int r) {
	if(l > r) return;

	if(s[l] == s[r]) {
		ans.push_back(s[l]);
		if(l != r) ans.push_back(s[l]);
		trace(l+1,r-1);
		return;
	}

	int o1 = 1 + go(l, r-1);
	int o2 = 1 + go(l+1, r);
	int op = go(l,r);

	if(o1 == op) {
		ans.push_back(s[r]);
		ans.push_back(s[r]);
		trace(l, r-1);
	} else {
		ans.push_back(s[l]);
		ans.push_back(s[l]);
		trace(l+1, r);
	}
}

int main() {
	while(cin >> s) {
		memset(dp, -1, sizeof dp);
		cout << go(0, s.size()-1) << " ";
		ans=""; trace(0, s.size()-1);

		int sz = (int)ans.size();
		for(int i=0; i<sz; i+=2) cout << ans[i];
		if(sz&1) sz--;
		for(int i=sz-1; i>=1; i-=2) cout << ans[i];
		cout << "\n";
	}

	return 0;
}
