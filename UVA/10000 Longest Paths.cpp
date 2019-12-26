#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;

vector<vector<int> > adj;
int dist[105];
bool vis[105];

void go(int u) {
	vis[u] = 1;
	for(int v : adj[u])
		dist[v] = min(dist[v], dist[u]-1);
}

vector<int> ts;

void topo(int u) {
	vis[u]=1;
	for(int v : adj[u]) if(!vis[v]) topo(v);
	ts.push_back(u);
}

int main() {
	int t=1,n,s,x,y;
	while(cin >> n && n) {
		adj.assign(105, {});
		memset(dist, 0, sizeof dist);

		cin >> s;
		while(cin >> x >> y && x)
			adj[x].push_back(y);

		memset(vis, 0, sizeof vis);
		topo(s);
		memset(vis, 0, sizeof vis);

		while(!ts.empty()) {
			int u = ts.back(); ts.pop_back();
			if(!vis[u]) go(u);
		}

		int mx=-1, ans;
		for(int i=1; i<=n; i++) {
			if(-dist[i] > mx) mx=-dist[i], ans=i;
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", t++, s, mx, ans);
	}

	return 0;
}
