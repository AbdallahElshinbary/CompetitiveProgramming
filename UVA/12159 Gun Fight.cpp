#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
vector<int> match, vis;

int dist(int x1, int y1, int x2, int y2) {
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
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
	int t=1,n,a,b,R,red,blue;
	int ax[305], ay[305], ap[305], ac[305], cnt[3];
	while(cin >> n && n) {
		adj.assign(305, {});
		memset(ac, 0, sizeof ac);

		for(int i=0; i<n; i++) cin >> ax[i] >> ay[i] >> ap[i];
		cin >> a >> b >> R; a--, b--;

		int x1=ax[a], y1=ay[a], x2=ax[b], y2=ay[b], d;

		cnt[1] = cnt[2] = 0;
		for(int i=0; i<n; i++) {
			if(!ap[i]) continue; //free tower
			d = (ax[i]-x1)*(y2-y1) - (ay[i]-y1)*(x2-x1); //cross product
			if(d > 0) ac[i] = 1, cnt[1]++;
			else ac[i] = 2, cnt[2]++;
		}

		if(cnt[1] < cnt[2]) red=1, blue=2;
		else red=2, blue=1;

		for(int i=0; i<n; i++) {
			if(!ac[i] || ac[i] == blue) continue;
			for(int j=0; j<n; j++) {
				if(!ac[j] || ac[j] == red) continue;
				if(ap[i] > ap[j] && dist(ax[i], ay[i], ax[j], ay[j]) <= R*R)
					adj[i].push_back(j);
			}
		}

		int MCBM = 0;
		match.assign(n, -1);
		for(int i=0; i<n; i++) {
			if(!ac[i] || ac[i] == blue) continue;
			vis.assign(n, 0);
			MCBM += Aug(i);
		}
		printf("Case %d: %d\n", t++, MCBM);
	}

	return 0;
}