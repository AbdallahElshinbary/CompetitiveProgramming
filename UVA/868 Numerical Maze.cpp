#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t,n,m,flag,ans;
int grid[22][22];
bool vis[22][22];

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

bool valid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void go(int x, int y, int z, int p) {
	if(!valid(x,y)) return;
	if(vis[x][y]) return;
	if(grid[x][y] != p) return;

	if(x == n-1) {flag=1, ans = min(ans, y); return;}

	if(p == z) z++, p=0;
	vis[x][y] = 1;
	go(x, y+1, z, p+1);
	go(x, y-1, z, p+1);
	go(x+1, y, z, p+1);
	go(x-1, y, z, p+1);
	vis[x][y] = 0;
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin >> grid[i][j];

		memset(vis, 0, sizeof vis);

		for(int i=0; i<m; i++) {
			if(grid[0][i] == 1) {
				flag=0, ans=1e9;
				go(0, i, 1, 1);
				if(flag) {printf("%d %d\n%d %d\n", 1, i+1, n, ans+1); break;}
			}
		}
		if(t) printf("\n");
	}

	return 0;
}
