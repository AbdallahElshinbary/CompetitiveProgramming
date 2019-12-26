#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, double> ii;

#define INF 1e9
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t,n;
	int arr[100005];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; i++) cin >> arr[i];
		sort(arr, arr+n, greater<int>());
		if(n < 3) cout << "0\n";
		else cout << min(arr[1]-1, n-2) << "\n";
	}

	return 0;
}
















