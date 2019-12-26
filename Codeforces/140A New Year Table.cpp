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

	double N,R,r,x;
	cin >> N >> R >> r;
	if(N == 1) {
		cout << (R >= r ? "YES" : "NO");
	} else {
		x = R*sin(PI/N)/(sin(PI/N)+1);
		cout << ((x > r || (fabs(x-r) < EPS)) ? "YES" : "NO");
	}

	return 0;
}
















