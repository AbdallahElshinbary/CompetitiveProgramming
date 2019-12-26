#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int color[100005];
vector<set<int> > v(100005);

int main() {
	int n,m,x,y;
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> color[i];
	for(int i=0; i<m; i++) {
		cin >> x >> y;
		if(color[x] == color[y]) continue;
		v[color[x]].insert(color[y]);
		v[color[y]].insert(color[x]);
	}

	int mx=-1, ans, c;
	for(int i=1; i<=n; i++) {
		c = (int) v[color[i]].size();
		if(mx < c) mx=c, ans=color[i];
		else if(mx == c) ans=min(ans, color[i]);
	}
	cout << ans;

	return 0;
}
