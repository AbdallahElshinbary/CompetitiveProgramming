#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
vector<vector<int> > adj2;
vector<int> vis, match;

int Aug(int l) {
	if(vis[l]) return 0;
	vis[l] = 1;
	for(int r : adj2[l]) {
		if(match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

void dfs(int r, int s) {
	vis[r] = 1;
	for(int x : adj[r]) {
		if(x > 1000) {adj2[s].push_back(x); continue;}
		if(!vis[x]) dfs(x, s);
	}
}

int main() {
	int t,n,m,k,num1,num2;
	string a,b;
	string rec[10000];
	map<string, int> mp;

	cin >> t;
	while(t--) {
		adj.assign(10000, {});
		adj2.assign(10000, {});
		mp.clear();

		cin >> n;
		for(int i=0; i<n; i++) {cin >> rec[i]; mp[rec[i]] = i+1;}
		num1 = n, num2 = 1000;

		cin >> m;
		for(int i=0; i<m; i++) {
			cin >> a >> b;
			mp[a] = ++num2;
			if(!mp[b]) mp[b] = ++num1;
			adj[mp[b]].push_back(mp[a]);
		}

		cin >> k;
		for(int i=0; i<k; i++) {
			cin >> a >> b;
			if(!mp[a]) mp[a] = ++num1;
			if(!mp[b]) mp[b] = ++num1;
			adj[mp[b]].push_back(mp[a]);
		}

		for(int i=1; i<=n; i++) {
			vis.assign(10000, 0);
			dfs(i, i);
		}

		int MCBM = 0;
		match.assign(10000, -1);
		for(int i=1; i<=n; i++) {
			vis.assign(10000, 0);
			MCBM += Aug(i);
		}

		cout << max(0, m - MCBM) << "\n";
		if(t) cout << "\n";
	}

	return 0;
}
