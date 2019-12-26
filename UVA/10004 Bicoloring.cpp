#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
int col[205];

bool check(int u) {
	for(int x : adj[u]) {
		if(col[x] == -1) {col[x] = 1-col[u]; check(x);}
		else if(col[x] == col[u]) return false;
	}
	return true;
}

int main() {
	int n,m,x,y;
	while(cin >> n && n) {
		cin >> m;
		adj.assign(205, {});
		memset(col, -1, sizeof col);
		while(m--) {
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		col[0]=0;
		cout << (check(0) ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
	}

	return 0;
}
