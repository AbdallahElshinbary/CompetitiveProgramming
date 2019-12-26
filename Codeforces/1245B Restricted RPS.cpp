#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-6
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t,n,a,b,c,win;
	string s,ans;
	char y;
	map<char, char> m = {{'R','P'},{'P','S'},{'S','R'}};
	cin >> t;

	while(t--) {
		cin >> n >> a >> b >> c; win=0;
		map<char, int> cnt;
		cnt['R']=a, cnt['P']=b, cnt['S']=c;

		cin >> s;
		char ans[105];
		bool flag[105]{};
		for(int i=0; i<n; i++) {
			y = m[s[i]];
			if(cnt[y]) win++, cnt[y]--, ans[i] = y, flag[i]=1;
		}

		if(win >= ceil(n*1.0/2)) {
			cout << "YES\n";
			for(int i=0; i<n; i++) {
				if(flag[i]) cout << ans[i];
				else {
					if(cnt['R']) {cout << 'R'; cnt['R']--;}
					else if(cnt['P']) {cout << 'P'; cnt['P']--;}
					else {cout << 'S'; cnt['S']--;}
				}
			}
			cout << "\n";
		}
		else cout << "NO\n";
	}

	return 0;
}





















