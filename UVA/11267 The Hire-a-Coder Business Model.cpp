#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int> > > adj;
priority_queue<pair<int, int> > pq;
int col[205];
bool vis[205];

bool bipartite(int u) {
	for(auto x : adj[u]) {
		if(col[x.first] == -1) {
			col[x.first] = 1-col[u];
			if(!bipartite(x.first)) return 0;
		} else if(col[x.first] == col[u]) return 0;
	}
	return 1;
}

void go(int u) {
	vis[u]=1;
	for(auto x : adj[u])
		if(!vis[x.first]) pq.push(make_pair(-x.second, -x.first));
}

int main() {
	int n,m,x,y,w,ans;
	while(cin >> n) {
		if(!n) break;
		cin >> m;

		adj.assign(205, {});
		memset(vis, 0, sizeof vis);
		memset(col, -1, sizeof col);

		for(int i=0; i<m; i++) {
			cin >> x >> y >> w;
			adj[x].push_back(make_pair(y,w));
			adj[y].push_back(make_pair(x,w));
		}
		col[1] = 0;
		if(!bipartite(1)) {cout << "Invalid data, Idiot!\n"; continue;}

		go(1); ans=0;
		while(!pq.empty()) {
			auto front = pq.top(); pq.pop();
			int w = -front.first, v = -front.second;
			if(!vis[v]) ans+=w, go(v);
			else if(w < 0) ans+=w;
		}
		cout << ans << "\n";
	}

	return 0;
}
