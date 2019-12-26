#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
	int t,n,m,c;
	string x;
	string co[125];
	map<string, int> mp;
	map<int, string> its;
	vector<vector<int> > adj;

	cin >> t;
	while(t--) {
		cin >> n;
		mp.clear(); its.clear();
		adj.assign(125, vector<int>(125, INF));

		for(int i=0; i<n; i++) {
			cin >> x; mp[x] = i; its[i] = x;
		}

		cin >> m;
		for(int i=0; i<m; i++) {
			cin >> co[i] >> c;
			while(c--) {
				cin >> x;
				adj[mp[x]][mp[co[i]]]=-1;
			}
		}

		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

		sort(co, co+m);
		set<string> pre;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(adj[j][mp[co[i]]] == -1) pre.insert(its[j]);
			}
			cout << co[i] << " " << pre.size();
			for(string s : pre) cout << " " << s;
			cout << "\n";
			pre.clear();
		}
	}

	return 0;
}
