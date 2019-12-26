#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char grid[12][12][12];
bool vis[12][12][12];
int k,n,m,x,y,tx,ty,tz,ans=0;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dz[] = {0,1,-1};

bool valid(int x, int y, int z) {
	return (x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < k && grid[z][x][y] != '#');
}

void dfs(int x, int y, int z) {
	vis[z][x][y]=1;

	for(int i=0; i<4; i++) {
		tx = x+dx[i], ty = y+dy[i];
		if(valid(tx,ty,z) && !vis[z][tx][ty]) ans++, dfs(tx,ty,z);
	}
	if(valid(x,y,z-1) && !vis[z-1][x][y]) ans++, dfs(x,y,z-1);
	if(valid(x,y,z+1) && !vis[z+1][x][y]) ans++, dfs(x,y,z+1);
}

int main() {
	cin >> k >> n >> m;
	for(int a=0; a<k; a++)
		for(int b=0; b<n; b++)
			for(int c=0; c<m; c++)
				cin >> grid[a][b][c];
	cin >> x >> y;
	dfs(--x, --y, 0);
	cout << ans+1;

	return 0;
}
