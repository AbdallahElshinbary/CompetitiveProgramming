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

	int n, cnt=0;
	int arr[105];
	bool vis[105]{};
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);
	for(int i=0; i<n; i++) {
		if(vis[i]) continue;
		vis[i] = 1, cnt++;
		for(int j=i+1; j<n; j++)
			if(arr[j]%arr[i] == 0) vis[j]=1;
	}
	cout << cnt;

	return 0;
}






















