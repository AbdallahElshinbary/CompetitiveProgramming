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

	int q,h,n,ans;
	int arr[200005];
	cin >> q;
	while(q--) {
		cin >> h >> n; ans=0;
		for(int i=0; i<n; i++) cin >> arr[i];
		arr[n] = 0;

		int cur = h;
		for(int i=1; i<n; i++) {
			if(cur == arr[i]) continue;
			cur = arr[i]+1;
			if(cur-arr[i+1] > 2) {ans++, cur=arr[i]-1;}
			else cur = arr[i+1];
		}
		cout << ans << "\n";
	}

	return 0;
}
























