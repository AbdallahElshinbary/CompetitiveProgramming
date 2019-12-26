#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s,x;
	map<string, int> m;

	cin >> s;
	for(int i=0; i<sz(s); i++) {
		x = "";
		for(int j=i; j<sz(s); j++) {
			x += s[j];
			m[x]++;
		}
	}

	int ans = 0;
	for(auto it : m)
		if(it.second >= 2)
			ans = max(ans, sz(it.first));
	cout << ans;

	return 0;
}





















