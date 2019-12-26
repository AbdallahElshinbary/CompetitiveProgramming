#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
vector<int> topo;
int vis[100005];
int ans;

void dfs1(int u) {
	vis[u]=1;
	for(int x : adj[u]) if(!vis[x]) dfs1(x);
	topo.push_back(u);
}

void dfs2(int u) {
	vis[u]=1;
	for(int x : adj[u]) if(!vis[x]) dfs2(x);
}

int main() {
	int t,n,m,x,y;
	cin >> t;
	while(t--) {
		ans = 0;
		adj.assign(100005, {});
		memset(vis, 0, sizeof vis);
		cin >> n >> m;
		for(int i=0; i<m; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for(int i=1; i<=n; i++)
			if(!vis[i]) dfs1(i);

		memset(vis, 0, sizeof vis);
		while(!topo.empty()) {
			x = topo.back(), topo.pop_back();
			if(!vis[x]) ans++, dfs2(x);
		}
		cout << ans << "\n";
	}

	return 0;
}
