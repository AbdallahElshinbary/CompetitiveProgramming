#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
vector<int> ans;
int income[1000005];

void khan(int n) {
	queue<int> q;
	for(int i=1; i<=n; i++)
		if(income[i] == 0) q.push(i);

	while(!q.empty()) {
		int u = q.front(); q.pop();
		ans.push_back(u);
		for(int x : adj[u])
			if(--income[x] == 0) q.push(x);
	}
}

int main() {
	int n,m,a,b;
	while(cin >> n >> m && n) {
		ans.clear();
		adj.assign(1000005, {});
		memset(income, 0, sizeof income);
		while(m--) {
			cin >> a >> b;
			income[b]++;
			adj[a].push_back(b);
		}
		khan(n);
		if(ans.size() < n) {cout << "IMPOSSIBLE\n"; continue;}
		for(int x : ans) cout << x << "\n";
	}

	return 0;
}
