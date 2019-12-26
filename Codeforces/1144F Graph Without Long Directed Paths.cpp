#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj(200005);
pair<int, int> edges[200005];
bool vis[200005], out[200005];

void dfs(int u, bool o) {
	vis[u]=1, out[u]=o;

	for(int x : adj[u])
		if(!vis[x]) dfs(x, !o);
}

int main() {
	int n, m, u, v;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges[i] = {u,v};
	}

	dfs(1, 1);
	for(int i=0; i<m; i++) {
		if(out[edges[i].first] && out[edges[i].second]) {cout << "NO"; return 0;}
		if(!out[edges[i].first] && !out[edges[i].second]) {cout << "NO"; return 0;}
	}

	cout << "YES\n";
	for(int i=0; i<m; i++) {
		if(out[edges[i].first]) cout << "0";
		else cout << "1";
	}

	return 0;
}
