#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,s,n,r1,c1,r2,c2;
	int grid[105][105];
	cin >> t;
	while(t--) {
		cin >> s >> n;
		memset(grid, 0, sizeof grid);

		for(int i=0; i<n; i++) {
			cin >> r1 >> c1 >> r2 >> c2;
			r1--, c1--, r2--, c2--;
			for(int a=r1; a<=r2; a++)
				for(int b=c1; b<=c2; b++)
					grid[a][b] = 1;
		}

		for(int i=0; i<s; i++) {
			for(int j=0; j<s; j++) {
				if(i > 0) grid[i][j] += grid[i-1][j];
				if(j > 0) grid[i][j] += grid[i][j-1];
				if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
			}
		}

		int mx = 0, sub;
		for(int i=0; i<s; i++) {
			for(int j=0; j<s; j++) {
				for(int k=i; k<s; k++) {
					for(int l=j; l<s; l++) {
						sub = grid[k][l];
						if(i > 0) sub -= grid[i-1][l];
						if(j > 0) sub -= grid[k][j-1];
						if(i > 0 && j > 0) sub += grid[i-1][j-1];

						if(!sub) mx = max(mx, (k-i+1)*(l-j+1));
					}
				}
			}
		}

		cout << mx << endl;
	}

	return 0;
}
