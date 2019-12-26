#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e12
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int n,m;
string a="wow",b,x;
ll dp[3][1000006];

ll go(int i, int j) {
	if(i == n) return 1;
	if(j == m) return 0;

	ll &ret = dp[i][j];
	if(ret != -1) return ret;
	ret = 0;

	if(a[i] == b[j])
		ret += go(i+1, j+1);
	ret += go(i, j+1);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> x;
	for(int i=0; i<sz(x); i++) {
		if(x[i] == x[i+1] && x[i] == 'v') b += 'w';
		else if(x[i] == 'o') b += 'o';
	}

	memset(dp, -1, sizeof dp);
	n=3, m=sz(b);
	cout << go(0, 0);

	return 0;
}




















