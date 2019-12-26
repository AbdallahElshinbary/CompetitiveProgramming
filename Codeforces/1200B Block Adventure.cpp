#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll t,n,m,k,i,x;
	ll h[105];
	cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		for(i=0; i<n; i++) cin >> h[i];
		for(i=0; i<n-1; i++) {
			if(h[i] >= h[i+1]) m += (h[i]-h[i+1]) + min(k, h[i+1]);
			else {
				x = abs(h[i]-h[i+1]);
				if(x <= k) m += min(k-x, h[i]);
				else m -= (x-k);
			}
			if(m < 0) break;
		}

		cout << (i == n-1 ? "YES\n" : "NO\n");
	}

}




















