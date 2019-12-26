#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	bool row[100005]{}, col[100005]{};

	ll n,m,x,y,rc=0,cc=0,ans;
	cin >> n >> m;
	ans = n*n;
	for(int i=0; i<m; i++) {
		cin >> x >> y;

		if(!row[x] && !col[y])
			ans -= (2*n)-1 - rc - cc, rc++, cc++;
		else if(!row[x] && col[y])
			ans -= n - cc, rc++;
		else if(row[x] && !col[y])
			ans -= n - rc, cc++;

		row[x] = col[y] = true;
		cout << ans << " ";
	}

	return 0;
}
