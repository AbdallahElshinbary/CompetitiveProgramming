#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 1e9

vector<vector<int> > adj;
vector<int> p, dist;
int res[105][105];

void augment(int v) {
	if(v == 1) return;
	else if(p[v] != -1) {
		augment(p[v]);
		res[v][p[v]] = -res[v][p[v]], res[p[v]][v] = INF;
	}
}

int main() {
	int n,m,x,y,w,ans;
	while(cin >> n && n) {
		adj.assign(105, {});
		memset(res, 0, sizeof res);
		ans = 0;

		cin >> m;
		for(int i=0; i<m; i++) {
			cin >> x >> y >> w;
			adj[x].push_back(y);
			adj[y].push_back(x);
			res[x][y] = res[y][x] = w;
		}

		for(int a=0; a<2; a++) {
			p.assign(105, -1);
			dist.assign(105, INF);
			dist[1] = 0;

			for(int i=0; i<n-1; i++) {
				for(int u=1; u<=n; u++) {
					for(int v : adj[u]) {
						if(dist[u] + res[u][v] < dist[v]) {
							p[v] = u;
							dist[v] = dist[u] + res[u][v];
						}
					}
				}
			}

			if(dist[n] != INF) augment(n);
			else {ans = -1; break;}
			ans += dist[n];
		}

		if(ans == -1) cout << "Back to jail\n";
		else cout << ans << "\n";
	}

	return 0;
}
