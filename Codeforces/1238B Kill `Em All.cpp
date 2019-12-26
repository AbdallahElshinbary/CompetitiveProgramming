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

	int q,n,r,x,ans,off;
	cin >> q;
	while(q--) {
		cin >> n >> r; ans=off=0;
		set<int> s;
		for(int i=0; i<n; i++) {cin >> x; s.insert(x);}
		for(auto i = s.rbegin(); i != s.rend(); i++) {
			if((*i)-off <= 0) break;
			ans++, off += r;
		}
		cout << ans << "\n";
	}

	return 0;
}
























