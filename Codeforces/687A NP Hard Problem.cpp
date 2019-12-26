#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj(100005);
int col[100005];
int p=0, a=0;

bool check(int u) {
	for(int x : adj[u]) {
		if(col[x] == -1) {
			col[x] = 1-col[u];
			if(!col[x]) p++; else a++;
			if(!check(x)) return false;
		}
		else if(col[x] == col[u]) return false;
	}
	return true;
}

int main() {
	int n,m,x,y;
	cin >> n >> m;
	memset(col, -1, sizeof col);
	while(m--) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i=1; i<=n; i++) {
		if(col[i] == -1) {
			col[i]=0, p++;
			if(!check(i)) {cout << -1; return 0;}
		}
	}

	cout << p << "\n";
	for(int i=1; i<=n; i++) if(!col[i]) cout << i << " ";
	cout << "\n" << a << "\n";
	for(int i=1; i<=n; i++) if(col[i]) cout << i << " ";

	return 0;
}
