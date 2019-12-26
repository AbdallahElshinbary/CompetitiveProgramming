#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-6
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n,c;
	ll a[200005]{}, b[200005]{};
	pair<ll,ll> ans[200005]{};

	cin >> n >> c;
	for(int i=1; i<n; i++) cin >> a[i];
	for(int i=1; i<n; i++) cin >> b[i];

	for(int i=2; i<=n; i++) {
		ans[i].first = a[i-1] + min(ans[i-1].first, ans[i-1].second);
		if(i == 2) ans[i].second = c+b[i-1];
		else ans[i].second = min(c+b[i-1]+ans[i-1].first, b[i-1]+ans[i-1].second);
	}

	for(int i=1; i<=n; i++) cout << min(ans[i].first, ans[i].second) << " ";

	return 0;
}









