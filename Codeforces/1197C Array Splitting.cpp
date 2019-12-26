#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	int arr[300005];
	ii d[300005];
	bool cut[300005];

	cin >> n >> k;
	for(int i=0; i<n; i++) cin >> arr[i];

	for(int i=0; i<n-1; i++)
		d[i] = mp(arr[i+1]-arr[i], i);

	sort(d, d+n, greater<ii>());
	for(int i=0; i<k-1; i++)
		cut[d[i].second] = 1;

	ll ans = 0;
	int cur = 0;
	for(int i=0; i<n; i++)
		if(cut[i])
			ans += arr[i]-arr[cur], cur = i+1;
	ans += arr[n-1]-arr[cur];
	cout << ans;

	return 0;
}
















