#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e12
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//solved with sin low
	double l;
	while(cin >> l) {
		 cout << fixed << setprecision(10) << (l/sin((108-45)*(PI/180))) * sin(108 *(PI/180)) << "\n";
	}

	return 0;
}




















