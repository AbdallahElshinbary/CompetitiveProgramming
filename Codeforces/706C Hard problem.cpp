#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 1e18

int n, e[100005];
string s[100005];
ll dp[100005][2];

ll go(int idx, int rev) {
	if(idx > 0 && s[idx] < s[idx-1]) return INF;
	if(idx == n-1) return 0;

	ll &ret = dp[idx][rev];
	if(ret != -1) return ret;
	ret = INF;

	if(s[idx] <= s[idx+1]) ret = min(ret, go(idx+1, 0));

	string x = s[idx+1];
	string xr=x;
	reverse(xr.begin(), xr.end());
	s[idx+1]=xr;
	ret = min(ret, e[idx+1] + go(idx+1, 1));
	s[idx+1]=x;

	return ret;
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++) cin >> e[i];
	for(int i=0; i<n; i++) cin >> s[i];
	memset(dp, -1, sizeof dp);

	ll ans = go(0, 0);
	reverse(s[0].begin(), s[0].end());
	ans = min(ans, e[0]+go(0, 1));
	cout << (ans == INF ? -1 : ans);

	return 0;
}
