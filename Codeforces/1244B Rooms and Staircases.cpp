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

	int t,n,l,r;
	string s;
	cin >> t;
	while(t--) {
		cin >> n >> s;
		for(l=0; l<n; l++) if(s[l] == '1') break;
		for(r=n-1; r>=0; r--) if(s[r] == '1') break;
		if(l == n) {cout << n << "\n"; continue;}
		cout << max((n-l)*2, (r+1)*2) << "\n";
	}


	return 0;
}
























