#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
vector<int> match, vis;

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int Aug(int l) {
	if(vis[l]) return 0;
	vis[l] = 1;
	for(int r : adj[l]) {
		if(match[r] == -1 || Aug(match[r])) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

int main() {
	int t,m,n,k,c;
	double gx[55], gy[55], hx[55], hy[55];
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> m >> n >> k;
		for(int i=0; i<m; i++) cin >> gx[i] >> gy[i];
		for(int i=0; i<n; i++) cin >> hx[i] >> hy[i];

		c = m-k;
		printf("Case #%d:\n", T);
		if(c > n) {printf("Too bad.\n\n"); continue;}

		double s=0.0, e=1000.0, d, ans=0.0;
		for(int x=0; x<100; x++) {
			d = (s+e)/2;
			adj.assign(55, {});

			for(int i=0; i<m; i++)
				for(int j=0; j<n; j++)
					if(dist(gx[i],gy[i], hx[j],hy[j]) <= d)
						adj[i].push_back(j);

			int MCBM = 0;
			match.assign(55, -1);
			for(int i=0; i<m; i++) {
				vis.assign(55, 0);
				MCBM += Aug(i);
			}

			if(MCBM < c) s = d;
			else ans = e = d;
		}
		printf("%.3f\n\n", ans);
	}

	return 0;
}
