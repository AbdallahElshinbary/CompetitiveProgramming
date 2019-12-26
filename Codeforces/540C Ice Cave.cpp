#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char grid[505][505];
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int n,m,r1,c1,r2,c2,tr,tc;

bool valid(int r, int c) {
	return (r >= 0 && r < n && c >= 0 && c < m);
}

void dfs(int r, int c) {
	grid[r][c] = 'O';
	for(int i=0; i<4; i++) {
		tr = r+dr[i], tc = c+dc[i];
		if(valid(tr, tc))
			if((tr == r2 && tc == c2) || (grid[tr][tc] == '.')) dfs(tr, tc);
	}
}

int main() {
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> grid[i][j];
	cin >> r1 >> c1 >> r2 >> c2;
	r1--, c1--, r2--, c2--;

	int x=0;
	for(int i=0; i<4; i++)
		if(valid(r2+dr[i], c2+dc[i]) &&	(grid[r2+dr[i]][c2+dc[i]] == '.' || (r2+dr[i] == r1 && c2+dc[i] == c1))) x++;
	if(grid[r2][c2] == 'X' && x < 1) {cout << "NO"; return 0;}
	if(grid[r2][c2] != 'X' && x <= 1) {cout << "NO"; return 0;}


	dfs(r1,c1);
	cout << (grid[r2][c2] == 'O' ? "YES" : "NO");

	return 0;
}
