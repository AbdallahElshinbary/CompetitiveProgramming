#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t=3,n=9,m,cnt,TC=1;
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
		cnt++;
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
				if(cnt == 2) return;
			}
		}
	}
}

int main() {
	while(cin >> m) {
		memset(grid, 0, sizeof grid);
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);
		bad = found = false;
		cnt = 0;

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(!(i == 0 && j == 0)) cin >> m;
				if(place(i, j, m)) {
					grid[i][j] = m;
					row[i] |= (1 << grid[i][j]);
					col[j] |= (1 << grid[i][j]);
				}
				else bad=true;
			}
		}
		cout << "Case " << TC++ << ": ";
		if(bad) {
			cout << "Illegal.\n";
			continue;
		}
		rec(0, 0);
		if(cnt == 1) cout << "Unique.\n";
		else if(cnt == 2) cout << "Ambiguous.\n";
		else if(!found) cout << "Impossible.\n";
	}

	return 0;
}
