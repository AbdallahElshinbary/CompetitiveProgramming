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

	double a,b,c,s,A;
	while(cin >> a >> b >> c) {
		s = (a+b+c)/2;
		A = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("The radius of the round table is: %.3lf\n", (A == 0 ? 0 : A/s));
	}
	return 0;
}




















