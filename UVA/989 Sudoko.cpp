#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t,n,m,TC=0;
int grid[9][9];
int row[9];
int col[9];
bool bad, found;

bool place(int x, int y, int num) {
	if(num == 0) return true;
	if(row[x] & (1 << num)) return false;
	if(col[y] & (1 << num)) return false;

	int r,c,d=1e2;
	for(int i=0; i<=x; i+=t)
		if(d > abs(i-x)) d=abs(i-x), r=i;
	d=1e2;
	for(int i=0; i<=y; i+=t)
		if(d > abs(i-y)) d=abs(i-y), c=i;

	for(int i=0; i<t; i++)
		for(int j=0; j<t; j++)
			if(grid[r+i][c+j] == num) return false;

	return true;
}

void rec(int x, int y) {
	if(y == n) x++, y=0;
	if(x == n) {
		found=true;
		for(int i=0; i<n; i++) {
			cout << grid[i][0];
			for(int j=1; j<n; j++) {
				cout << " " << grid[i][j];
			}
			cout << "\n";
		}
		return;
	}
	if(grid[x][y]) rec(x, y+1);
	else {
		for(int k=1; k<=9; k++) {
			if(place(x,y,k)) {
				row[x] |= (1 << k);
				col[y] |= (1 << k);
				grid[x][y] = k;
				rec(x, y+1);
				grid[x][y] = 0;
				row[x] &= ~(1 << k);
				col[y] &= ~(1 << k);
				if(found) return;
			}
		}
	}
}

int main() {
	while(cin >> t) {
		if(TC) cout << "\n";

		n = t*t;
		memset(grid, 0, sizeof grid);
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);
		bad = found = false;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cin >> m;
				if(place(i, j, m)) {
					grid[i][j] = m;
					row[i] |= (1 << grid[i][j]);
					col[j] |= (1 << grid[i][j]);
				}
				else bad=true;
			}
		}
		if(bad) {
			cout << "NO SOLUTION\n";
			continue;
		}
		rec(0, 0);
		if(!found) cout << "NO SOLUTION\n";
		TC++;
	}

	return 0;
}
