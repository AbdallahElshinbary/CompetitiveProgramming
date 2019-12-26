#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n,x1,y1,x2,y2,a,b,c,z1,z2,ans=0;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	while(n--) {
		cin >> a >> b >> c;
		z1 = a*x1 + b*y1 + c;
		z2 = a*x2 + b*y2 + c;
		if((z1 > 0 && z2 < 0) || (z1 < 0 && z2 > 0)) ans++;
	}
	cout << ans;

	return 0;
}
















