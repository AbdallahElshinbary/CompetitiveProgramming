#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<pair<int, int> > > adj;
bool vis[100005];
int num[100005];
int cnt=0;

void dfs(int r, int m) {
	vis[r]=1, cnt++;
	for(auto a : adj[r]) {
		int u = a.first, w = a.second;
		if(vis[u]) continue;

		int x = max(m+w, w);
		if(x > num[u]) continue;

		dfs(u, x);
	}
}

int main() {
	int n,x,w;
	adj.assign(100005, {});
	cin >> n;
	for(int i=1; i<=n; i++) cin >> num[i];
	for(int i=2; i<=n; i++) {
		cin >> x >> w;
		adj[i].push_back(make_pair(x, w));
		adj[x].push_back(make_pair(i, w));
	}

	dfs(1, 0);
	cout << n-cnt;

	return 0;
}
