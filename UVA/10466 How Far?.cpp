#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e12
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,T,r,t;
	double x,y,an;
	while(cin >> n >> T) {
		x = y = 0;
		for(int i=0; i<n; i++) {
			cin >> r >> t;
			an = 2*PI*T/t;
			x += r * cos(an);
			y += r * sin(an);
			cout << fixed << setprecision(4) << sqrt(x*x + y*y);
			if(i < n-1) cout << " ";
		}
		cout << "\n";
	}

	return 0;
}




















