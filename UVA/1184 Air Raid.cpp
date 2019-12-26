#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
vector<int> match, vis;

int Aug(int l) {
	if(vis[l]) return 0;
	vis[l] = 1;
	for(int r : adj[l]) {
		if(match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int main() {
	int t,n,m,x,y;
	cin >> t;
	while(t--) {
		adj.assign(125, {});

		cin >> n >> m;
		for(int i=0; i<m; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
		}

		int MCBM = 0;
		match.assign(125, -1);
		for(int i=1; i<=n; i++) {
			vis.assign(125, 0);
			MCBM += Aug(i);
		}

		cout << n-MCBM << "\n";
	}

	return 0;
}
