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
	cin.tie(0);

	string s;
	cin >> s;
	int mn = s[0]-'a';
	cout << "Mike\n";
	for(int i=1; i<sz(s); i++) {
		if(mn >= s[i]-'a') cout << "Mike\n";
		else cout << "Ann\n";
		mn = min(mn, s[i]-'a');
	}

	return 0;
}




















