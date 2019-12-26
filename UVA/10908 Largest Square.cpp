#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, m, q, r, c;
char arr[105][105];

bool valid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

bool check(int l) {
	int x = r-(l/2), y=c-(l/2);
	if(!valid(x,y) || !valid(x+l-1, y+l-1)) return 0;

	for(int i=0; i<l-1; i++) {
		if(arr[x][y+i] != arr[x][y+i+1]) return 0;
		if(arr[x+l-1][y+i] != arr[x+l-1][y+i+1]) return 0;
		if(arr[x+i][y] != arr[x+i+1][y]) return 0;
		if(arr[x+i][y+l-1] != arr[x+i+1][y+l-1]) return 0;
	}
	return 1;
}


int main() {
	cin >> t;
	while(t--) {
		cin >> n >> m >> q;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin >> arr[i][j];

		printf("%d %d %d\n", n, m, q);

		int ans;
		while(q--) {
			cin >> r >> c;
			ans = 1;
			for(int i=1;;i++) {
				if(check(ans+2)) ans+=2;
				else break;
			}
			cout << ans << "\n";
		}
	}

	return 0;
}
