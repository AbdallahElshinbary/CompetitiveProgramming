#include <bits/stdc++.h>
using namespace std;

bool vis[26]{};
map<char, vector<char> > mp;

int dfs(char node) {
	vis[node-'A'] = true;
	int cnt = 1;
	for(int i=0; i<mp[node].size(); i++) {
		if(!vis[mp[node][i]-'A'])
			cnt += dfs(mp[node][i]);
	}
	return cnt;
}

int main() {
	int t,trees, acrons;
	string letters,edges;
	char x,y;
	cin >> t;
	while(t--) {
		trees = acrons = 0;
		mp.clear();
		memset(vis, false, sizeof vis);

		while(cin >> edges && edges[0] != '*') {
			x = edges[1], y = edges[3];
			mp[x].push_back(y), mp[y].push_back(x);
		}
		cin >> letters;
		for(char c : letters) {
			if(c != ',' && !vis[c-'A']) {
				if(dfs(c) == 1)
					acrons++;
				else
					trees++;
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acrons);
	}

	return 0;

}

