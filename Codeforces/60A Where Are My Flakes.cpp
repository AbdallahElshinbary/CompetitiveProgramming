#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m,x,l,r;
	string a,b,c,d;
	cin >> n >> m;
	l=1, r=n;
	for(int i=0; i<m; i++) {
		cin >> a >> b >> c >> d >> x;
		if(c == "left") r=min(r, x-1);
		else l=max(l, x+1);
	}
	if(l > r) cout << -1;
	else cout << r-l+1;

	return 0;
}



