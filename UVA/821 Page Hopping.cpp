#include <bits/stdc++.h>
using namespace std;

#define INF 1e9


int main() {
	int t=1,x,y,n;
	int adj[105][105];
	map<int, int> mp;

	while(cin >> x >> y && x) {
		for(int i=0; i<105; i++) fill(adj[i], adj[i]+105, INF);
		mp.clear(); n=0;

		if(!mp[x]) mp[x]=++n;
		if(!mp[y]) mp[y]=++n;
		adj[mp[x]][mp[y]]=1;

		while(cin >> x >> y && x) {
			if(!mp[x]) mp[x]=++n;
			if(!mp[y]) mp[y]=++n;
			adj[mp[x]][mp[y]]=1;
		}

		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

		double ans=0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(i != j) ans += adj[i][j];

		printf("Case %d: average length between pages = %.3f clicks\n", t++, ans/(n*(n-1)));
	}

	return 0;
}
