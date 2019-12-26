#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char grid[55][55];
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int n,m,pr,pc,tr,tc,cnt;

bool valid(int r, int c) {
	return (r >= 0 && r < n && c >= 0 && c < m);
}

void dfs(int r, int c) {
	if(grid[r][c] == 'G') cnt++;
	grid[r][c] = '#';

	for(int i=0; i<4; i++) {
		tr = r+dr[i], tc = c+dc[i];
		if(grid[tr][tc] == 'T') return;
	}

	for(int i=0; i<4; i++) {
		tr = r+dr[i], tc = c+dc[i];
		if(valid(tr, tc) && grid[tr][tc] != '#')
			dfs(tr, tc);
	}
}

int main() {
	while(cin >> m >> n) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin >> grid[i][j];
				if(grid[i][j] == 'P') pr=i, pc=j;
			}
		}
		cnt = 0;
		dfs(pr,pc);
		cout << cnt << "\n";
	}

	return 0;
}
