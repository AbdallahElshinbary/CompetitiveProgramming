#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<pair<int, int> > > adj;
priority_queue<pair<int, int> > pq;
bool vis[205];

void go(int u) {
	vis[u] = 1;
	for(auto x : adj[u])
		if(!vis[x.first]) pq.push(make_pair(x.second, -x.first));
}

int main() {
	int n,r,x,y,z,w,mn,t=1;

	while(cin >> n >> r && n) {
		adj.assign(105, {});
		mn=1e9;
		memset(vis, 0, sizeof vis);

		for(int i=0; i<r; i++) {
			cin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
			adj[y].push_back(make_pair(x, w));
		}
		cin >> x >> y >> z;
		go(x);

		while(!pq.empty()) {
			auto front = pq.top(); pq.pop();
			int w = front.first, u = -front.second;
			if(!vis[u]) {
				mn=min(mn, w);
				if(u == y) break;
				go(u);
			}
		}
		while(!pq.empty()) pq.pop();

		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", t++, (int)ceil(z*1.0/(mn-1)));
	}

	return 0;
}
