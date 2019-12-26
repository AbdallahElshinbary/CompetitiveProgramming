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

	ll n,x1,x2,k,b;
	pair<ll, ll> y[100005];
	cin >> n >> x1 >> x2;

	for(int i=0; i<n; i++) {
		cin >> k >> b;
		y[i] = {k*x1 +b, k*x2+b};
	}
	sort(y, y+n);

	for(int i=0; i<n-1; i++)
		if(y[i].second > y[i+1].second) {cout << "YES\n"; return 0;}
	cout << "NO\n";

	return 0;
}




















