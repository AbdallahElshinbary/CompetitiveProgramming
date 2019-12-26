#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> v;
vector<vector<pair<int, int> > > adj(100005);
int parent[100005];

void bfs(int r) {
	queue<int> q; q.push(r);
	while(!q.empty()) {
		int u=q.front(), n=0; q.pop();
		for(auto x : adj[u]) {
			q.push(x.first);
			n += x.second;
		}
		if(n == (int)adj[u].size() && parent[u] == 1) v.push_back(u);
	}
}

int main() {
	int n, p, c, r;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> p >> c;
		if(p == -1) {r = i; parent[p]=0; continue;}
		adj[p].push_back(make_pair(i, c));
		parent[i] = c;
	}
	bfs(r);
	sort(v.begin(), v.end());
	for(int x : v) cout << x << " ";
	if(v.empty()) cout << -1;

	return 0;
}
