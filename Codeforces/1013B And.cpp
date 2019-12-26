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

	bool found[100005];
	int arr[100005], cnt[100005]{};

	int n,x;
	cin >> n >> x;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		found[arr[i]] = 1;
		if((++cnt[arr[i]]) == 2) {cout << 0; return 0;}
	}

	int f, ans = -1;
	for(int i=0; i<n; i++) {
		f = arr[i]&x;
		if(f == arr[i]) continue;
		if(++cnt[f] == 2) {
			if(found[f]) {ans=1; break;}
			else ans = 2;
		}
	}
	cout << ans;

}




















