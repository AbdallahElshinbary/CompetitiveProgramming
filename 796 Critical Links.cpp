#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > AdjList;
bool vis[1005];
int num[1005], low[1005], parent[1005], cnt;
set<pair<int,int> > ans;

void AP(int u) {
	num[u] = low[u] = ++cnt;
	vis[u] = true;
	for(int v : AdjList[u]) {
		if(!vis[v]) {
			parent[v] = u;
			AP(v);
			if(low[v] > num[u])
				ans.insert({min(u,v), max(u,v)});
			low[u] = min(low[u], low[v]);
		}
		else if(v != parent[u])
			low[u] = min(low[u], num[v]);
	}
}

int main() {
	int n,x,y,m;
	while(cin >> n) {
		AdjList.assign(1005, {});
		ans.clear();
		memset(vis, false, sizeof vis);
		memset(num, 0, sizeof num);
		memset(low, 0, sizeof num);
		memset(parent, 0, sizeof num);
		cnt = 0;

		for(int i=0; i<n; i++) {
			scanf("%d (%d) ", &x, &m);
			for(int j=0; j<m; j++) {
				cin >> y;
				AdjList[x].push_back(y);
			}
		}

		for(int i=1; i<=n; i++) {
			if(!vis[i])
				AP(i);
		}

		printf("%d critical links\n", (int)ans.size());

		for(auto x : ans)
			printf("%d - %d\n", x.first, x.second);

		printf("\n");
	}

	return 0;
}

