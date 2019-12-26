#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj(105);
bool vis[105], ans[105];
int cycles=0;

void dfs(int u, int p) {
	vis[u] = ans[u] = 1;
	for(int x : adj[u]) {
		if(!vis[x]) dfs(x, u);
		else if(x != p && ans[x]) cycles++;
	}
	ans[u] = 0;
}


int main() {
	int n,m,x,y;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1, -1);
	if(cycles != 1) {cout << "NO"; return 0;}
	for(int i=1; i<=n; i++) if(!vis[i]) {cout << "NO"; return 0;}
	cout << "FHTAGN!";

	return 0;
}
