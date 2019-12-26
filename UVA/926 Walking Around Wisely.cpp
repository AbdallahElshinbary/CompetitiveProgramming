#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t,n,w,xs,ys,xe,ye,a,b;
bool grid[55][55][55][55];
ll dp[55][55];

int valid(int x, int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= n);
}

ll go(int x, int y) {
	if(x == xe && y == ye) return 1;

	ll &ret = dp[x][y];
	if(ret != -1) return ret;
	ret = 0;

	if(valid(x+1,y) && grid[x][y][x+1][y]) ret += go(x+1, y);
	if(valid(x,y+1) && grid[x][y][x][y+1]) ret += go(x, y+1);

	return ret;
}

int main() {
	char c;
	map<char, pair<int, int> > mp;
	mp['N'] = {0, 1};
	mp['S'] = {0, -1};
	mp['E'] = {1, 0};
	mp['W'] = {-1, 0};

	cin >> t;
	while(t--) {
		cin >> n;
		cin >> xs >> ys >> xe >> ye;
		memset(grid, 1, sizeof grid);

		cin >> w;
		for(int i=0; i<w; i++) {
			cin >> a >> b >> c;
			if(!valid(a+mp[c].first, b+mp[c].second)) continue;
			grid[a][b][a+mp[c].first][b+mp[c].second] = 0;
			grid[a+mp[c].first][b+mp[c].second][a][b] = 0;
		}

		memset(dp, -1, sizeof dp);
		cout << go(xs,ys) << "\n";
	}


	return 0;
}