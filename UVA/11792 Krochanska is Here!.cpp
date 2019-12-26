#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
int cnt[10005], dist[10005];

int bfs(int r) {
	int ret=0;
	queue<int> q; q.push(r); dist[r]=0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : adj[u]) {
			if(dist[v] == -1) {
				dist[v] = dist[u]+1;
				if(cnt[v] > 1) ret += dist[v];
				q.push(v);
			}
		}
	}
	return ret;
}

int main() {
	int t,n,m,x,p,mn,ans;
	cin >> t;
	while(t--) {
		adj.assign(10005, {});
		memset(cnt, 0, sizeof cnt);

		cin >> n >> m;
		while(m--) {
			p = -1;
			while(cin >> x && x) {
				if(p != -1) adj[p].push_back(x), adj[x].push_back(p);
				cnt[x]++, p = x;
			}
		}

		mn = INT_MAX;
		for(int i=1; i<=n; i++) {
			if(cnt[i] > 1) {
				memset(dist, -1, sizeof dist);
				x = bfs(i);
				if(x < mn) mn=x, ans=i;
			}
		}
		printf("Krochanska is in: %d\n", ans);
	}

	return 0;
}
