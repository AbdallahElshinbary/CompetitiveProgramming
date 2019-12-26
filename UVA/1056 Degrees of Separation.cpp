#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
	int t=1,n,m,num;
	string x,y;
	int adj[55][55];
	map<string, int> mp;

	while(cin >> n >> m && n) {
		for(int i=0; i<55; i++) fill(adj[i], adj[i]+55, INF);
		mp.clear(); num = 0;

		for(int i=0; i<m; i++) {
			cin >> x >> y;
			if(!mp[x]) mp[x]=++num;
			if(!mp[y]) mp[y]=++num;
			adj[mp[x]][mp[y]]=adj[mp[y]][mp[x]]=1;
		}

		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

		printf("Network %d: ", t++);

		int mx=-1, dis=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i != j) {
					if(adj[i][j] == INF) {dis=1; break;}
					mx = max(mx, adj[i][j]);
				}
			}
			if(dis) break;
		}
		if(dis) printf("DISCONNECTED\n\n");
		else printf("%d\n\n", mx);
	}

	return 0;
}
