#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
int p[100000];

void bfs(int r) {
	queue<int> q; q.push(r); p[r]=r;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int x : adj[u])
			if(p[x] == -1) {p[x]=u; q.push(x);}
	}
}

int main() {
	int n,r1,r2,x;
	adj.assign(100000, {});
	cin >> n >> r1 >> r2;
	for(int i=1; i<=n; i++) {
		if(i == r1) continue;
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	memset(p, -1, sizeof p);

	bfs(r2);
	for(int i=1; i<=n; i++) {
		if(i == r2) continue;
		cout << p[i] << " ";
	}

	return 0;
}
