#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
bool conn[10][10][10][10];

bool valid(int i, int j) {
	return (i > 0 && i <= n && j > 0 && j <= n);
}

int check(int i, int j, int x, int y, int l) {
	for(int a=0; a<l; a++)
		if(!conn[i+a][j][i+a+1][j]) return 0;
	for(int a=0; a<l; a++)
		if(!conn[i][j+a][i][j+a+1]) return 0;

	for(int a=0; a<l; a++)
		if(!conn[x-a][y][x-a-1][y]) return 0;
	for(int a=0; a<l; a++)
		if(!conn[x][y-a][x][y-a-1]) return 0;

	return l;
}

int main() {
	char c;
	int t=0, i,j;
	bool found;
	map<int, int> mp;

	while(cin >> n >> m) {
		memset(conn, 0, sizeof conn);
		mp.clear();

		while(m--) {
			cin >> c >> i >> j;
			if(c == 'H') conn[i][j][i][j+1] = conn[i][j+1][i][j] = 1;
			else conn[j][i][j+1][i] = conn[j+1][i][j][i] = 1;
		}

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				for(int k=1; k<=n; k++) {
					if(!valid(i+k, j+k)) break;
					mp[(check(i, j, i+k, j+k, k))]++;
				}
			}
		}

		if(t) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n", ++t);

		found = 0;
		for(auto x : mp) {
			if(x.first > 0) {
				printf("%d square (s) of size %d\n", x.second, x.first);
				found=1;
			}
		}
		if(!found) printf("No completed squares can be found.\n");
	}

	return 0;
}
