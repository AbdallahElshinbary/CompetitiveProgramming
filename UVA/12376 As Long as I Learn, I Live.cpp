#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
int learn[105];
int sum, last;

bool cmp(int &a, int &b) {
	return learn[a] > learn[b];
}

void dfs(int u) {
	sum += learn[u];
	if(adj[u].size() == 0) {last=u; return;}
	sort(adj[u].begin(), adj[u].end(), cmp);
	dfs(adj[u][0]);
}

int main() {
	int t,n,m,x,y;
	cin >> t;
	for(int T=1; T<=t; T++) {
		adj.assign(105, {});

		cin >> n >> m;
		for(int i=0; i<n; i++) cin >> learn[i];
		for(int i=0; i<m; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
		}

		sum=0;
		dfs(0);
		printf("Case %d: %d %d\n", T, sum, last);
	}

	return 0;
}
