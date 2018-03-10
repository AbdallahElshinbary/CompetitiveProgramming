#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100005;
vector<vector<int> > AdjList;
bool vis[SIZE];
stack<int> st;

void dfs1(int u) {
	vis[u] = true;
	for(int x : AdjList[u])
		if(!vis[x])
			dfs1(x);
	st.push(u);
}

void dfs2(int u) {
	vis[u] = true;
	for(int x : AdjList[u])
		if(!vis[x])
			dfs2(x);
}

int main() {
	int t,n,m,x,y,dom;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		AdjList.assign(SIZE, {});
		memset(vis, false, sizeof vis);
		dom = 0;
		while(m--) {
			cin >> x >> y;
			AdjList[x].push_back(y);
		}
		for(int i=1; i<=n; i++)
			if(!vis[i])
				dfs1(i);
		memset(vis, false, sizeof vis);
		while(!st.empty()) {
			int x = st.top(); st.pop();
			if(!vis[x])
				dom++, dfs2(x);
		}

		cout << dom << "\n";
	}

	return 0;
}

