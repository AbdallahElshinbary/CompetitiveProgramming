#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int t,r,c;
int grid[105][105], run[105][105];
bool vis[105][105];
string name;

void dfs(int x, int y) {
	vis[x][y] = 1;

	int tx,ty;
	for(int i=0; i<4; i++) {
		tx = x+dx[i], ty = y+dy[i];
		if(tx >= 0 && tx < r && ty >= 0 && ty < c && grid[tx][ty] < grid[x][y]) {
			if(!vis[tx][ty]) dfs(tx, ty);
			run[x][y] = max(run[x][y], 1 + run[tx][ty]);
		}
	}
}

int main() {

	cin >> t;
	while(t--) {
		memset(vis, 0, sizeof vis);
		memset(run, 0, sizeof run);

		cin >> name >> r >> c;
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				cin >> grid[i][j];

		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				if(!vis[i][j]) dfs(i, j);

		int ans = 0;
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				ans = max(ans, run[i][j]);

		cout << name << ": " << ans+1 << "\n";
	}

	return 0;
}