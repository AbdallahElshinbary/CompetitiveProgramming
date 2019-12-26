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

	int n,m;
	while(cin >> n >> m) {
		double an[1005];
		double x = 360.0/n, c=0, ans=0;
		for(int i=1; i<=n; i++)
			an[i] = c, c += x;
		int i=2,j=0;
		x = 360.0/(n+m), c = 0;
		while(i+j < n+m) {
			if(i > n) {j++; continue;}
			if(abs(an[i]-(c+x)) <= x || j > m) {
				ans += 10000*min(abs(an[i]-(c+x)), abs(an[i]-(c+x+x)))/360.0;
				i++;
			} else j++;
			c += x;
		}
		cout << fixed << setprecision(4) << ans << "\n";
	}

	return 0;
}
















