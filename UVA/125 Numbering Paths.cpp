#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
	int t=0, n,m,x,y;
	int adj[32][32];

	while(cin >> m) {
		memset(adj, 0, sizeof adj); n=-1;
		while(m--) {
			cin >> x >> y;
			adj[x][y]=1;
			n = max(n, max(x,y));
		}

		for(int k=0; k<=n; k++)
			for(int i=0; i<=n; i++)
				for(int j=0; j<=n; j++)
					adj[i][j] += adj[i][k]*adj[k][j];

		for(int k=0; k<=n; k++)
			if(adj[k][k])
				for(int i=0; i<=n; i++)
					for(int j=0; j<=n; j++)
						if(adj[i][k] && adj[k][j])
							adj[i][j] = -1;

		cout << "matrix for city " << t++ << "\n";
		for(int i=0; i<=n; i++) {
			cout << adj[i][0];
			for(int j=1; j<=n; j++)
				cout << " " << adj[i][j];
			cout << "\n";
		}
	}

	return 0;
}
