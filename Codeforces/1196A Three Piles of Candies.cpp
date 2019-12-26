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
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	ll a[3];
	cin >> t;
	while(t--) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3);
		ll x=a[0],y=a[1],z=a[2], d;
		d = min(z, y-x);
		x += d, z -= d;
		if(z) cout << x+(z/2) << "\n";
		else cout << x << "\n";
	}

	return 0;
}
















