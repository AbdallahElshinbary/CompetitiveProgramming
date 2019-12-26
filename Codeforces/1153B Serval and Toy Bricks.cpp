#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m,h;
	int f[105], l[105];
	int g[105][105], ans[105][105]{};

	cin >> n >> m >> h;
	for(int i=0; i<m; i++) cin >> f[i];
	for(int i=0; i<n; i++) cin >> l[i];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> g[i][j];

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!g[i][j]) continue;
			ans[i][j] = min(l[i], f[j]);
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}




	return 0;
}
