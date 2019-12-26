#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 1e9

vector<vector<int> > adj;
ll p[105], dist[105], used[105];
ll res[105][105], cost[105][105];
ll n,m,d,k,x,y,z,ans,f;

void augment(int v, ll minEdge) {
	if(v == 0) {f = minEdge; return;}
	else if(p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f, res[v][p[v]] += f;
		cost[v][p[v]] = -cost[v][p[v]];
		cost[p[v]][v] = -cost[p[v]][v];
	}
}

bool spfa(int src, int sink) {
	queue<int> q; q.push(src);

	for(int i=0; i<=n; i++)
    	dist[i] = INF, used[i] = 0;

	dist[src] = 0, used[src] = 1;

	while(!q.empty()) {
		int u = q.front(); q.pop();
		used[u] = 0;
		for(int v : adj[u]) {
			if(dist[u] + cost[u][v] < dist[v] && res[u][v] > 0) {
				p[v] = u;
				dist[v] = dist[u] + cost[u][v];
				if(!used[v]) q.push(v), used[v]=1;
			}
		}
	}

	return dist[sink] != INF;
}

int main() {

	while(cin >> n >> m) {
		adj.assign(105, {});
		memset(res, 0, sizeof res);
		memset(cost, 0, sizeof cost);
		ans = 0;

		for(int i=0; i<m; i++) {
			cin >> x >> y >> z;
			adj[x].push_back(y);
			adj[y].push_back(x);
			cost[x][y] = cost[y][x] = z;
		}
		cin >> d >> k;

		for(int u=1; u<=n; u++)
			for(int v : adj[u])
				res[u][v] = res[v][u] = k;

		adj[0].push_back(1);
		res[0][1] = d;
		cost[0][1] = 0;

		ll totflow = 0;
		while(spfa(0, n)) {
			augment(n, INF);
			totflow += f;
			ans += dist[n]*f;
		}

		if(totflow != d) cout << "Impossible.\n";
		else cout << ans << "\n";
	}

	return 0;
}
