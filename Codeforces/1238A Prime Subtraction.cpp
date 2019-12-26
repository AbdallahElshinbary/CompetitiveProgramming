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
	cin.tie(0);

	int t;
	ll x,y;
	cin >> t;
	while(t--) {
		cin >> x >> y;
		cout << (x-y == 1 ? "NO\n" : "YES\n");
	}

	return 0;
}
























