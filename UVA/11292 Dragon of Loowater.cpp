#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dr[20005], kn[20005];

int main() {
	int n,m;
	while(cin >> n >> m && n) {
		for(int i=0; i<n; i++) cin >> dr[i];
		for(int i=0; i<m; i++) cin >> kn[i];
		if(n > m) {
			cout << "Loowater is doomed!\n";
			continue;
		}
		sort(dr, dr+n);
		sort(kn, kn+m);

		int i, j, ans = 0;
		for(i=0, j=0; i<n && j<m; ) {
			if(kn[j] >= dr[i]) ans += kn[j], i++, j++;
			else if(kn[j] < dr[i]) j++;
		}
		if(i == n) cout << ans << "\n";
		else cout << "Loowater is doomed!\n";
	}

	return 0;
}
