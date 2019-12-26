#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int adj[5][5];
int ans[9];

void go(int x, int cnt) {
	ans[cnt] = x;

	if(cnt == 8) {
		for(int i : ans) cout << i;
		cout << "\n";
		return;
	}

	for(int i=1; i<=5; i++) {
		if(adj[x][i]) {
			adj[x][i] = adj[i][x] = 0;
			go(i, cnt+1);
			adj[x][i] = adj[i][x] = 1;
		}
	}
}

int main() {
	adj[1][2] = adj[1][5] = adj[1][3] = 1;
	adj[2][1] = adj[2][3] = adj[2][5] = 1;
	adj[3][1] = adj[3][2] = adj[3][4] = adj[3][5] = 1;
	adj[4][3] = adj[4][5] = 1;
	adj[5][1] = adj[5][2] = adj[5][3] = 1;

	go(1, 0);


	return 0;
}
