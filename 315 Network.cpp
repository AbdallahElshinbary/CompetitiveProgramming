#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > AdjList;
bool vis[105];
int num[105], low[105], parent[105], cnt, root, rootChildren;
bitset<105> vertices;

void AP(int u) {
	num[u] = low[u] = ++cnt;
	vis[u] = true;
	for(int v : AdjList[u]) {
		if(!vis[v]) {
			parent[v] = u;
			if(u == root)
				rootChildren++;
			AP(v);
			if(low[v] >= num[u] && u != root)
				vertices.set(u);
			low[u] = min(low[u], low[v]);
		}
		else if(v != parent[u])
			low[u] = min(low[u], num[v]);
	}
}

int main() {
	int n,x,y;
	string s;
	while(cin >> n && n) {
		AdjList.assign(105, {});
		memset(vis, false, sizeof vis);
		memset(num, 0, sizeof num);
		memset(low, 0, sizeof num);
		memset(parent, 0, sizeof num);
		vertices.reset();
		cnt = 0;

		while(cin >> x && x) {
			getline(cin, s);
			stringstream ss(s);
			while(ss >> y)
				AdjList[x].push_back(y), AdjList[y].push_back(x);
		}

		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				root = i, rootChildren = 0;
				AP(i);
				if(rootChildren > 1) vertices.set(i);
			}
		}
		cout <<  vertices.count() << "\n";
	}

	return 0;
}

