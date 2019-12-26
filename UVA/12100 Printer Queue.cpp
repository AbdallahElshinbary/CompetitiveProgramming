#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,n,m,x,mx,ans;
	int freq[10];

	cin >> t;
	while(t--) {
		queue<pair<int, int> > q; mx = -1, ans = 0;
		memset(freq, 0, sizeof freq);

		cin >> n >> m;
		for(int i=0; i<n; i++) {
			cin >> x; q.push(make_pair(x, i));
			mx = max(mx, x), freq[x]++;
		}

		while(1) {
			auto a = q.front(); q.pop();
			if(a.first < mx) {q.push(a); continue;}
			if(a.second == m) break;
			freq[mx]--, ans++;
			while(!freq[mx]) mx--;
		}

		while(!q.empty()) q.pop();

		cout << ans+1 << "\n";

	}

	return 0;
}
