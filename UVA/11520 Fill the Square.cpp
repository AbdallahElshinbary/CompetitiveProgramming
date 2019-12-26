#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char grid[12][12];

int idx[] = {0,0,1,-1};
int idy[] = {1,-1,0,0};
int t,n,x,y;
char c;

bool valid(int i, int j, char c) {
	for(int a=0; a<4; a++) {
		x = i+idx[a], y = j+idy[a];
		if(x >= 0 && x < n && y >= 0 && y < n) {
			if(c != grid[x][y]) continue;
			else return false;
		}
	}
	return true;
}

int main() {
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> n;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin >> grid[i][j];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(grid[i][j] != '.') continue;
				for(int k=0; k<26; k++) {
					c = 'A'+k;
					if(valid(i, j, c)) {
						grid[i][j] = c;
						break;
					}
				}
			}
		}
		cout << "Case " << T << ":\n";
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++)
				cout << grid[i][j];
			cout << "\n";
		}
	}

	return 0;
}
