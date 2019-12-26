#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char grid[1005][1005];
bool vis[1005][1005];
int ans[1005][1005];
int n,m,k,x,y,tx,ty,cnt=0;
vector<pair<int, int> > stk;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool valid(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int x, int y) {
	vis[x][y] = 1; stk.push_back(make_pair(x,y));
	for(int i=0; i<4; i++) {
		tx = x+dx[i], ty = y+dy[i];
		if(valid(tx, ty) && grid[tx][ty] == '*') cnt++;
		else if(valid(tx, ty) && grid[tx][ty] == '.' && !vis[tx][ty]) dfs(tx, ty);
	}
}

int main() {
	cin >> n >> m >> k;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> grid[i][j];

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(grid[i][j] == '.' && !vis[i][j]) {
				cnt = 0; dfs(i, j);
				for(auto s : stk) ans[s.first][s.second]=cnt;
				stk.clear();
			}
		}
	}

	for(int i=0; i<k; i++) {
		cin >> x >> y;
		cout << ans[--x][--y] << "\n";
	}

	return 0;
}
