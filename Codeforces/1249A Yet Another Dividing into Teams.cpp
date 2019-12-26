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

	int q,n;
	int arr[105];
	cin >> q;
	while(q--) {
		cin >> n;
		for(int i=0; i<n; i++) cin >> arr[i];
		sort(arr, arr+n);

		int ans = 1;
		for(int i=1; i<n; i++)
			if(arr[i]-arr[i-1] == 1) {ans++; break;}
		cout << ans << "\n";
	}

	return 0;
}









