#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string line;
int num=0;
map<string, int> mp;
map<int, string> st;
map<int, int> in;
vector<vector<int> > adj;
vector<int> v;

void dfs1(int r) {
	v.push_back(r);
	for(int i=0; i<(int)adj[r].size(); i++) dfs1(adj[r][i]);
}

void dfs2(int r) {
	v.push_back(r);
	for(int i=(int)adj[r].size()-1; i>=0; i--) dfs2(adj[r][i]);
}

int main() {
	adj.assign(5005, {});
	while(getline(cin, line)) {
		stringstream ss(line);
		string s;
		int p = -1;
		while(getline(ss, s, ',')) {
			if(!mp[s]) {mp[s]=++num; st[num]=s;}
			if(p == -1) {p = mp[s]; continue;}
			adj[p].push_back(mp[s]); in[mp[s]]++;
		}
	}
	cout << "2\n\n";

	for(int i=1; i<=num; i++) if(in[i]==0) {dfs1(i); break;}
	for(int i=(int)v.size()-1; i>=0; i--) cout << st[v[i]] << "\n";
	cout << "\n";
	v.clear();
	for(int i=1; i<=num; i++) if(in[i]==0) {dfs2(i); break;}
	for(int i=(int)v.size()-1; i>=0; i--) cout << st[v[i]] << "\n";

	return 0;
}
