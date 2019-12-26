#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int> > adj;
bool awake[30];

int main() {
	int n,m;
	string s;
	char x,y;
	set<int> ss;
	while(cin >> n >> m >> s) {
		ss.clear();
		adj.assign(30, {});
		memset(awake, 0, sizeof awake);

		for(char c : s) awake[c-'A']=1;
		for(int i=0; i<m; i++) {
			cin >> x >> y;
			x -= 'A', y -= 'A';
			adj[x].push_back(y);
			adj[y].push_back(x);
			ss.insert(x); ss.insert(y);
		}

		int left = n-3, ans=0, cnt;
		queue<int> q;

		while(true) {
			for(int a : ss) {
				if(awake[a]) continue;
				cnt = 0;
				for(int b : adj[a])	cnt += awake[b];
				if(cnt >= 3) q.push(a);
			}
			if(q.empty()) break;
			left -= q.size(), ans++;
			while(!q.empty()) awake[q.front()]=1, q.pop();
		}

		if(left == 0) printf("WAKE UP IN, %d, YEARS\n", ans);
		else printf("THIS BRAIN NEVER WAKES UP\n");
	}

	return 0;
}
