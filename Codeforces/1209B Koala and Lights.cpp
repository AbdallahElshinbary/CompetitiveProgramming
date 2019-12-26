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

	int n, a[105], b[105];
	string s;
	bool on[105];
	cin >> n >> s;
	for(int i=0; i<n; i++) on[i] = (s[i] == '1');
	for(int i=0; i<n; i++) cin >> a[i] >> b[i];

	int ans=0, cnt;
	for(int i=0; i<10000; i++) {
		cnt = 0;
		for(int j=0; j<n; j++) {
			cnt += on[j];
			if(b[j] == i) {
				on[j] = !on[j];
				b[j] += a[j];
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;

	return 0;
}






















