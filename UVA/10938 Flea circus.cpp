#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
bool vis[5005];
vector<int> tmp;
bool found;

void dfs(int x, int y) {
	tmp.push_back(x);
	vis[x] = 1;
	if(x == y) {found=1; return;}

	for(int u : adj[x]) {
		if(!vis[u]) dfs(u, y);
		if(found) return;
	}

	tmp.pop_back();
}

int main() {
	int n,x,y,l,s;
	while(cin >> n && n) {
		adj.assign(5005, {});

		for(int i=1; i<n; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		cin >> l;
		for(int i=0; i<l; i++) {
			cin >> x >> y;
			memset(vis, 0, sizeof vis);
			tmp.clear(); found = 0;

			dfs(x, y);
			s = (int)tmp.size();
			if(s%2 == 1) printf("The fleas meet at %d.\n", tmp[s/2]);
			else printf("The fleas jump forever between %d and %d.\n", min(tmp[s/2-1], tmp[s/2]), max(tmp[s/2-1], tmp[s/2]));
		}
	}

	return 0;
}

