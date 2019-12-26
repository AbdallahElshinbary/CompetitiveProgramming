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

	int n,ans=0;
	int a[100005], b[100005];
	bool vis[100005]{};
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];

	for(int i=0,j=0; i<n&&j<n; ) {
		if(vis[a[i]]) i++;
		else {
			if(a[i] == b[j]) vis[a[i]]=1,i++,j++;
			else {
				while(a[i] != b[j])
					vis[b[j]]=1, ans++, j++;
				vis[a[i]]=1, i++, j++;
			}
		}
	}
	cout << ans;

	return 0;
}


















