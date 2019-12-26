#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
bool vis[30];
bool cycle;
int cnt;

void dfs(int r, int p) {
	vis[r]=1, cnt++;
	for(int x : adj[r]) {
		if(!vis[x]) dfs(x, r);
		else if(x != p) cycle = 1;
	}
}

int main() {
	int t,x,y,tree,acorn;
	string s;
	cin >> t; cin.ignore();
	while(t--) {
		adj.assign(30, {});
		memset(vis, 0, sizeof vis);
		tree = acorn = 0;

		while(getline(cin, s) && s[0] != '*') {
			x = s[1]-'A', y = s[3]-'A';
			adj[x].push_back(y); adj[y].push_back(x);
		}
		getline(cin, s);
		for(char c : s) {
			if(isalpha(c) && !vis[c-'A']) {
				cycle=0, cnt=0; dfs(c-'A', -1);
				if(!cycle) {
					if(cnt == 1) acorn++;
					else tree++;
				}
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
	}

	return 0;
}