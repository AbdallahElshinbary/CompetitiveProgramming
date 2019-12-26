#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
	int n;
	string x;
	vector<vector<int> > adj;

	while(cin >> n) {
		adj.assign(105, vector<int>(105, INF));

		for(int i=2; i<=n; i++) {
			for(int j=1; j<i; j++) {
				cin >> x;
				if(x[0] != 'x') adj[i][j] = adj[j][i] = stoi(x);
			}
		}

		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					if(i == j) adj[i][j]=0;
					else adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
				}
			}
		}

		int ans=-1;
		for(int i=1; i<=n; i++) ans = max(ans, adj[1][i]);
		cout << ans << "\n";
	}

	return 0;
}