#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define mp make_pair
#define sz(s) (int)s.size()

int dist(pair<ii, int> &a, pair<ii, int> &b) {
	return sqrt(((a.first.first-b.first.first)*(a.first.first-b.first.first)) +
				((a.first.second-b.first.second)*(a.first.second-b.first.second)) +
				((a.second-b.second)*(a.second-b.second)));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x,y,z,n=0,near;
	pair<ii, int> a[5005];
	while(cin >> x >> y >> z && (x+y+z))
		a[n++] = mp(mp(x,y), z);

	int ans[10]{};
	for(int i=0; i<n; i++) {
		near = INF;
		for(int j=0; j<n; j++) {
			if(i == j) continue;
			near = min(near, dist(a[i], a[j]));
		}
		if(near > 9) continue;
		ans[near]++;
	}
	for(int x : ans) printf("%4d", x);
	printf("\n");

	return 0;
}
















