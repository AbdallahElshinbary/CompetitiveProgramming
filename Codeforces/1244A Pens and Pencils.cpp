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

	int t,a,b,c,d,k,x,y;
	cin >> t;
	while(t--) {
		cin >> a >> b >> c >> d >> k;
		x = ceil(a*1.0/c), y = ceil(b*1.0/d);
		if(x+y > k) cout << "-1\n";
		else cout << x << " " << y << "\n";
	}

	return 0;
}
























