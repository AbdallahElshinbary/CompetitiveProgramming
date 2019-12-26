#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
vector<int> match, vis;

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
	int t,n,x1,x2,y,z;
	char colon;
	cin >> t;
	int h[505],m[505],a[505],b[505],c[505],d[505];
	while(t--) {
		adj.assign(505, {});

		cin >> n;
		for(int i=0; i<n; i++)
			cin >> h[i] >> colon >> m[i] >> a[i] >> b[i] >> c[i] >> d[i];

		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				x1 = h[i]*60+m[i];
				x2 = h[j]*60+m[j];
				y = abs(a[i]-c[i]) + abs(b[i]-d[i]);
				z = abs(c[i]-a[j]) + abs(d[i]-b[j]);
				if(x1+y+z < x2) adj[i].push_back(j);
			}
		}

		int MCBM = 0;
		match.assign(505, -1);
		for(int i=0; i<n; i++) {
			vis.assign(505, 0);
			MCBM += Aug(i);
		}
		cout << n - MCBM << "\n";
	}

	return 0;
}
