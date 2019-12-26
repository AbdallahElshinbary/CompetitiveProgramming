#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,l,r,e,xa,xb,ok;
	int x[105], y[105];
	while(cin >> n && n) {
		for(int i=0; i<2*n; i++)
			cin >> x[i] >> y[i];
		for(int a=-500; a<=500; a++) {
			for(int b=-500; b<=500; b++) {
				l = r = ok = 0;
				for(int k=0; k<2*n; k++) {
					e = a*x[k] + b*y[k];
					if(e < 0) l++;
					else if(e > 0) r++;
					else break;
				}
				if(l == r && l == n && r == n) {ok=1, xa=a, xb=b; break;}
			}
			if(ok) {cout << xa << " " << xb << "\n"; break;}
 		}
	}


	return 0;
}
















