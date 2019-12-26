#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
int col[305];

bool bipartite(int u) {
	for(int x : adj[u]) {
		if(col[x] == -1) {
			col[x] = 1-col[u];
			if(!bipartite(x)) return false;
		} else if(col[x] == col[u]) return false;
	}
	return true;
}

int main() {
	int n,x,y;
	while(cin >> n && n) {
		adj.assign(305, {});
		memset(col, -1, sizeof col);

		while(cin >> x >> y && x) {
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		bool ok=1;
		for(int i=1; i<=n; i++) {
			if(col[i] == -1) {
				col[i] = 0;
				if(!bipartite(i)) {ok=0; break;}
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}

	return 0;
}
