#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > v(1000005);

int main() {
	int n,m,x,y;
	while(cin >> n >> m) {
		for(int i=1; i<=n; i++) {
			cin >> x;
			v[x].push_back(i);
		}
		for(int i=0; i<m; i++) {
			cin >> x >> y;
			if(v[y].size() < x) cout << "0\n";
			else cout << v[y][x-1] << "\n";
		}
		v.clear();
	}

	return 0;
}
