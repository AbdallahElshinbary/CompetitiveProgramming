#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 1e9
#define ii pair<int, int>

int n,m,bx,by,tx,ty,T,ans;
char grid[55][55];
int dist[55][55][55][55];
int dp[1<<11][11];
int dpDist[11][11];
ii tr[11];

int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,-1,1,-1,1};

bool valid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void bfs(int px, int py) {
	dist[px][py][px][py] = 0;
	queue<ii> q; q.push(ii(px,py));
	while(!q.empty()) {
		ii u = q.front(); q.pop();
		for(int i=0; i<4; i++) {
			tx = u.first+dx[i], ty = u.second+dy[i];
			if(valid(tx,ty) && grid[tx][ty] != '#' && dist[px][py][tx][ty] == -1) {
				dist[px][py][tx][ty] = 1 + dist[px][py][u.first][u.second];
				q.push(ii(tx,ty));
			}
		}
	}
}

int go(int mask, int last) {
	if(mask == (1 << T)-1) return dpDist[last][0];

	int &ret = dp[mask][last];
	if(ret != -1) return ret;
	ret = INF;

	for(int i=1; i<T; i++)
		if(!(mask & (1 << i))) ret = min(ret, dpDist[last][i] + go(mask | (1 << i), i));

	return ret;
}

int main() {
	while(cin >> n >> m && n) {
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin >> grid[i][j];

		T = 1;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(grid[i][j] == '~') grid[i][j] = '#';
				else if(grid[i][j] == '*') {
					for(int k=0; k<8; k++) {
						tx = i+dx[k], ty = j+dy[k];
						if(valid(tx,ty)) {
							if(grid[tx][ty] == '!' || grid[tx][ty] == '@') grid[tx][ty]='x';
							else if(grid[tx][ty] != '*' && grid[tx][ty] != 'x') grid[tx][ty] = '#';
						}
					}
					grid[i][j] = '#';
				} else if(grid[i][j] == '!') tr[T++] = ii(i,j);
				else if(grid[i][j] == '@') bx=i, by=j, tr[0]=ii(bx,by);
			}
		}

		bool bad=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(grid[i][j] == 'x') bad=1;
		if(bad) {cout << "-1\n"; continue;}

		memset(dist, -1, sizeof dist);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(grid[i][j] != '#')
					bfs(i,j);

		int d;
		for(int i=0; i<T; i++) {
			for(int j=i+1; j<T; j++) {
				d = dist[tr[i].first][tr[i].second][tr[j].first][tr[j].second];
				dpDist[i][j] = dpDist[j][i] = (d == -1 ? INF : d);
				if(d == -1) bad=1;
			}
		}
		if(bad) {cout << "-1\n"; continue;}

		memset(dp, -1, sizeof dp);
		ans = go(1, 0);
		cout << (ans == INF ? -1 : ans) << "\n";
	}


	return 0;
}
