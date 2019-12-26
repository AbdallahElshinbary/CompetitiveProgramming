#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q,n,m,t,ans;
	char x;
	int r[50005], c[50005];

	cin >> q;
	while(q--) {
		cin >> n >> m;
		memset(r, 0, sizeof r);
		memset(c, 0, sizeof c);
		ans = INF;

		vector<pair<int, int> > v;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin >> x;
				if(x == '*') r[i]++, c[j]++, v.push_back(mp(i,j));
			}
		}
		sort(v.begin(), v.end());

		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				t = (n-r[i]) + (m-c[j]);
				if(!binary_search(v.begin(), v.end(), mp(i,j))) t--;
				ans = min(ans, max(0,t));
			}
		}
		cout << ans << "\n";
	}

	return 0;
}

















