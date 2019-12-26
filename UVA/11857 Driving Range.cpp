#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<pair<int, int> > > adj;
priority_queue<pair<int, int> > pq;
bool vis[100005];

void go(int u) {
	vis[u] = 1;
	for(auto x : adj[u])
		if(!vis[x.first]) pq.push(make_pair(-x.second, -x.first));
}

int main() {
	int n,m,x,y,w,mx,cnt;
	while(cin >> n >> m && n) {
		adj.assign(1000005, {});
		memset(vis, 0, sizeof vis);

		for(int i=0; i<m; i++) {
			cin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
			adj[y].push_back(make_pair(x, w));
		}

		go(0);
		mx=-1, cnt=1;
		while(!pq.empty()) {
			auto v = pq.top(); pq.pop();
			int u = -v.second, w = -v.first;
			if(!vis[u]) mx=max(mx,w), cnt++, go(u);
		}
		if(cnt == n) cout << mx << "\n";
		else cout << "IMPOSSIBLE\n";
	}

	return 0;
}
