#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
vector<int> match, vis;

int dist(int x1, int y1, int x2, int y2) {
	return ceil(sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ));
}

int Aug(int l) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int r : adj[l]) {
        if (match[r] == -1 || Aug(match[r])) {
            match[r] = l; return 1;
        }
    }
    return 0;
}

int main() {
	int t,n,k;
	int px[105], py[105];
	string pc[105];

	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i=0; i<n; i++) cin >> px[i] >> py[i] >> pc[i];

		int l=0, h=10000, m, ans=-1;
		while(l <= h) {
			m = (l+h)/2;
			adj.assign(105, {});

			for(int i=0; i<n; i++) {
				if(pc[i] == "blue") continue;
				for(int j=0; j<n; j++) {
					if(pc[j] == "red") continue;
					if(dist(px[i],py[i],px[j],py[j]) <= m)
						adj[i].push_back(j);
				}
			}

			int MCBM = 0;
			match.assign(n, -1);
			for (int l=0; l<n; l++) {
			    if(pc[l] == "blue") continue;
				vis.assign(n, 0);
			    MCBM += Aug(l);
			}

			if(MCBM < k) l = m+1;
			else ans = m, h = m-1;
		}
		if(ans != -1) cout << ans << "\n";
		else cout << "Impossible\n";
	}

	return 0;
}
