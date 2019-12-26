#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);

	string x,y;
	int t, ans;
	cin >> t;
	while(t--) {
		ans = 0;
		cin >> x >> y;
		for(int i=sz(x)-1, j=sz(y)-1; i>=0 && j >=0; ) {
			if(x[i] == '1') {
				if(y[j] == '1') break;
				else i--, j--;
			} else {
				if(y[j] == '0')
					i--, j--;
				else
					ans++, i--;
			}
		}

		cout << ans << "\n";
	}

}



















