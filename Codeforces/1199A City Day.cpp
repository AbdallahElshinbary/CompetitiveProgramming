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
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,x,y;
	int a[100005]{};
	cin >> n >> x >> y;
	for(int i=0; i<n; i++) cin >> a[i];

	bool ok;
	for(int i=0; i<n; i++) {
		ok = 1;
		for(int j=i-1; j>=max(i-x, 0); j--)
			if(a[i] >= a[j]) {ok=0; break;}
		for(int j=i+1; j<min(i+y+1, n); j++)
			if(a[i] >= a[j]) {ok=0; break;}
		if(ok) {cout << i+1; break;}
	}
}



















