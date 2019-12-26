#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
vector<int> vis, match;

double dist(int x1, int y1, int x2, int y2) {
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
	int t,n,m;
	int lx[105], ly[105], rx[105], ry[105];
	cin >> t;
	while(t--) {
		adj.assign(105, {});

		cin >> n >> m;
		for(int i=0; i<n; i++) cin >> lx[i] >> ly[i];
		for(int i=0; i<m; i++) cin >> rx[i] >> ry[i];

		double d1,d2,d3;
		for(int i=0; i<n-1; i++) {
			d1 = dist(lx[i], ly[i], lx[i+1], ly[i+1]) * 2.0;

			for(int j=0; j<m; j++) {
				d2 = dist(lx[i], ly[i], rx[j], ry[j]);
				d3 = dist(rx[j], ry[j], lx[i+1], ly[i+1]);
				if(d2+d3 <= d1) adj[j].push_back(i);
			}
		}

		match.assign(n, -1);
		for(int i=0; i<m; i++) {
			vis.assign(m, 0);
			Aug(i);
		}

		int p = 0;
		for(int i=0; i<n; i++) if(match[i] != -1) p++;
		printf("%d\n", n+p);

		for(int i=0; i<n-1; i++) {
			printf("%d %d ", lx[i], ly[i]);
			if(match[i] != -1) printf("%d %d ", rx[match[i]], ry[match[i]]);
		}
		printf("%d %d\n", lx[n-1], ly[n-1]);
		if(t) printf("\n");
	}

	return 0;
}