#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
vector<int> topo;
int vis[2005];
int ans;

bool inSquare(double x1, double y1, double d1, double x2, double y2) {
	double l=x1-d1/2, r=x1+d1/2;
	double t=y1-d1/2, b=y1+d1/2;
	return (x2 >= l && x2 <= r && y2 >= t && y2 <= b);
}

void dfs1(int u) {
	vis[u]=1;
	for(int x : adj[u]) if(!vis[x]) dfs1(x);
	topo.push_back(u);
}

void dfs2(int u) {
	vis[u]=1;
	for(int x : adj[u]) if(!vis[x]) dfs2(x);
}

int main() {
	int t,n,ans;
	int ax[2005], ay[2005], ad[2005];

	cin >> t;
	while(t--) {
		ans=0;
		topo.clear();
		adj.assign(2005, {});
		memset(vis, 0, sizeof vis);

		cin >> n;
		for(int i=0; i<n; i++)
			cin >> ax[i] >> ay[i] >> ad[i];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(inSquare(ax[i],ay[i],ad[i],ax[j],ay[j]))
					adj[i].push_back(j);
			}
		}

		for(int i=0; i<n; i++) if(!vis[i]) dfs1(i);
		memset(vis, 0, sizeof vis);
		for(int i=(int)topo.size()-1; i>=0; i--) if(!vis[topo[i]]) ans++, dfs2(topo[i]);
		cout << ans << "\n";
	}

	return 0;
}
