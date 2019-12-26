#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m;
	char c;
	char a[105][105];
	int rc[105][30]{}, cc[105][30]{};
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> c;
			a[i][j] = c;
			rc[i][c-'a']++, cc[j][c-'a']++;
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			c = a[i][j];
			if(rc[i][c-'a'] == 1 && cc[j][c-'a'] == 1) cout << c;
		}
	}

	return 0;
}
