#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,r,c,k,x,ti,tj;
	int grid[105][105]{}, ans[105][105]{};
	int di[] = {0,0,1,-1};
	int dj[] = {1,-1,0,0};

	while(cin >> n >> r >> c >> k && n) {
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				cin >> grid[i][j];

		for(int K=0; K<k; K++) {
			memset(ans, -1, sizeof ans);
			for(int i=0; i<r; i++) {
				for(int j=0; j<c; j++) {
					x = (grid[i][j] + 1) % n;
					for(int l=0; l<4; l++) {
						ti = i+di[l], tj = j+dj[l];
						if(ti < 0 || ti >= r || tj < 0 || tj >= c) continue;
						if(grid[ti][tj] == x) ans[ti][tj] = grid[i][j];
					}
					if(ans[i][j] == -1) ans[i][j] = grid[i][j];
				}
			}
			memcpy(grid, ans, sizeof grid);
		}

		for(int i=0; i<r; i++) {
			for(int j=0; j<c-1; j++) cout << ans[i][j] << " ";
			cout << ans[i][c-1] << "\n";
		}
	}



	return 0;
}







