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
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t,n,k;
	int arr[200005];
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i=0; i<n; i++) cin >> arr[i];

		ll sum = 0;
		vector<int> v;
		for(int i=0; i<n; i++) {
			sum += arr[i];
			if((sum&1) && k>1) {
				v.push_back(i), sum=0, k--;
			}
		}
		if(!(sum&1)) {cout << "NO\n"; continue;}
		v.push_back(n-1); cout << "YES\n";
		for(int x : v) cout << x+1 << " ";
		cout << "\n";
	}

	return 0;
}
















