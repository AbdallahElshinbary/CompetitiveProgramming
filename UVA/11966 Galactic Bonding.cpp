#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
bool vis[1005];

double dist(double x1, double y1, double x2, double y2) {
	return sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
}

void dfs(int u) {
	vis[u]=1;
	for(int x : adj[u]) if(!vis[x]) dfs(x);
}

int main() {
	int t,n,ans;
	double d,z;
	double ax[1005], ay[1005];
	cin >> t;
	for(int T=1; T<=t; T++) {
		adj.assign(1005, {});
		memset(vis, 0, sizeof vis);

		cin >> n >> d;
		for(int i=0; i<n; i++)
			cin >> ax[i] >> ay[i];

		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				z = dist(ax[i], ay[i], ax[j], ay[j]);
				if(z <= d) adj[i].push_back(j), adj[j].push_back(i);
			}
		}

		ans = 0;
		for(int i=0; i<n; i++)
			if(!vis[i]) ans++, dfs(i);
		printf("Case %d: %d\n", T, ans);
	}

	return 0;
}
