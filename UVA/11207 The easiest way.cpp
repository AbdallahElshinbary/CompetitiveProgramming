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

	int n;
	double w,h,x,mx,ans;
	while(cin >> n && n) {
		mx = -1;
		for(int i=1; i<=n; i++) {
			cin >> w >> h;
			x = -1;
			x = max(x, min(w,h/4));
			x = max(x, min(h,w/4));
			x = max(x, min(w,h)/2);
			if(x > mx) mx=x, ans=i;
		}
		cout << ans << "\n";
	}


	return 0;
}
















