#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e12
#define EPS 1e-6
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int n;
ll arr[105], sum[105];
ll dp[105][105];
bool done[105][105];

ll go(int l, int r) {
	if(l > r) return 0;

	ll &ret = dp[l][r];
	if(done[l][r]) return ret;
	done[l][r] = 1;

	ret = -INF;
	for(int i=l; i<=r; i++)
		ret = max(ret, (sum[i]-sum[l-1]) - go(i+1, r));
	for(int i=r; i>=l; i--)
		ret = max(ret, (sum[r]-sum[i-1]) - go(l, i-1));

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> n && n) {
		for(int i=1; i<=n; i++) cin >> arr[i];
		sum[0] = 0;
		for(int i=1; i<=n; i++) sum[i] = sum[i-1] + arr[i];
		memset(done, 0, sizeof done);
		cout << go(1, n) << "\n";
	}

	return 0;
}




















