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
	cin.tie(NULL);

	int t,a,b;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		cout << (__gcd(a,b) == 1 ? "Finite\n" : "Infinite\n");
	}

	return 0;
}





















