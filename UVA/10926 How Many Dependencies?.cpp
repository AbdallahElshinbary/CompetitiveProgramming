#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
bool vis[105];
int dep[105];

void dfs(int r, int u) {
	dep[r]++; vis[u]=1;
	for(int v : adj[u]) {
		if(!vis[v]) dfs(r, v);
	}
}

int main() {
	int n,t,x;
	while(cin >> n && n) {
		adj.assign(105, {});
		memset(dep, 0, sizeof dep);

		for(int i=1; i<=n; i++) {
			cin >> t;
			while(t--) {cin >> x; adj[i].push_back(x);}
		}

		int mx=-1, ans;
		for(int i=1; i<=n; i++) {
			memset(vis, 0, sizeof vis);
			dfs(i, i);
		}
		for(int i=1; i<=n; i++) if(dep[i] > mx) mx=dep[i], ans=i;
		cout << ans << "\n";
	}

	return 0;
}