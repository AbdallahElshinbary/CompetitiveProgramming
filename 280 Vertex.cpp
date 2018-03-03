#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > v(105);
vector<int> res;
bool vis[105];

void dfs(int node) {
	for(int i=0; i<(int)v[node].size(); i++) {
		if(!vis[v[node][i]]) {
			vis[v[node][i]] = true;
			dfs(v[node][i]);
		}
	}
}

int main() {
	int n,s,x,nv,st;
	while(cin >> n && n != 0) {
		while(cin >> s && s != 0) {
			while(cin >> x && x != 0) {
				v[s].push_back(x);
			}
		}
		cin >> nv;
		while(nv--) {
			memset(vis, false, sizeof vis);
			res.clear();
			cin >> st;
			dfs(st);
			for(int i=1; i<=n; i++)
				if(!vis[i])
					res.push_back(i);
			cout << res.size();
			for(int i=0; i<(int)res.size(); i++)
				cout << " " << res[i];
			cout << "\n";
		}
		v.clear();
		v.resize(105);
	}

	return 0;
}

