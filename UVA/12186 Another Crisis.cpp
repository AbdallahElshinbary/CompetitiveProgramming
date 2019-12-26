#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
int n,t,p;

bool cmp(int &a, int &b) {
	return adj[a].size() < adj[b].size();
}

int dfs(int r) {
	int ratio=ceil(adj[r].size()*t/100.0);
	if(adj[r].size() == 0) return 1;

	vector<int> v;
	for(int x : adj[r]) v.push_back(dfs(x));

	sort(v.begin(), v.end());
	int ans=0;
	for(int i=0; i<ratio; i++) ans += v[i];
	return ans;
}

int main() {
	while(cin >> n >> t && n) {
		adj.assign(100005, {});
		for(int i=1; i<=n; i++) {
			cin >> p;
			adj[p].push_back(i);
		}
		for(int i=0; i<=n; i++) sort(adj[i].begin(), adj[i].end(), cmp);
		cout << dfs(0) << "\n";
	}

	return 0;
}
