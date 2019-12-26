#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
vector<int> stk;
int dfs_num[2005], dfs_low[2005];
bool in_stk[2005];
int num, scc;

void tarjan(int r) {
	dfs_num[r] = dfs_low[r] = num++;
	in_stk[r] = 1; stk.push_back(r);

	for(int x : adj[r]) {
		if(dfs_num[x] == -1) tarjan(x);
		if(in_stk[x]) dfs_low[r] = min(dfs_low[r], dfs_low[x]);
	}
	if(dfs_num[r] == dfs_low[r]) {
		while(1) {
			int u = stk.back(); stk.pop_back(); in_stk[u]=0;
			if(u == r) break;
		}
		scc++;
	}
}

int main() {
	int n,m,v,w,p;
	while(cin >> n >> m && n) {
		num = 1, scc = 0;
		stk.clear();
		adj.assign(2005, {});
		memset(in_stk, 0, sizeof in_stk);
		memset(dfs_num, -1, sizeof dfs_num);

		for(int i=0; i<m; i++) {
			cin >> v >> w >> p;
			adj[v].push_back(w);
			if(p == 2) adj[w].push_back(v);
		}
		for(int i=1; i<=n; i++) if(dfs_num[i] == -1) tarjan(i);
		cout << (scc == 1 ? "1\n" : "0\n");
	}

	return 0;
}
