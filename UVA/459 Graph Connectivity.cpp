#include <bits/stdc++.h>
using namespace std;

bool vis[30];
map<char, vector<char> > v;

void dfs(char c) {
	vis[c-'A'] = true;
	for(int i=0; i<v[c].size(); i++) {
		if(!vis[v[c][i]-'A'])
			dfs(v[c][i]);
	}
}

int main() {
	int t,cnt;
	char x,y,end;
	string s;
	cin >> t;
	while(t--) {
		cin >> end;
		cin.ignore();
		while(getline(cin,s)) {
			if(s.empty())
				break;
			x = s[0], y=s[1];
			v[x].push_back(y);
			v[y].push_back(x);
		}
		cnt = 0;
		for(char c='A'; c<=end; c++)
			if(!vis[c-'A'])
				cnt++, dfs(c);
		cout << cnt << "\n";
		if(t)
			cout << "\n";
		memset(vis, false, sizeof vis);
		v.clear();
	}

	return 0;
}

