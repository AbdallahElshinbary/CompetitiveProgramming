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

	int a1,a2,k1,k2,n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;

	int mnans,mxans,nn=n;

	nn -= (k1-1)*a1 + (k2-1)*a2;
	if(nn > 0) {
		cout << min(nn, a1+a2) << " ";
	} else {cout << "0 ";}

	if(k1 < k2) {
		mxans = min(n/k1, a1);
		n -= min(k1*(n/k1) ,k1*a1);
		mxans += min(n/k2, a2);
		cout << mxans;
	}
	else {
		mxans = min(n/k2, a2);
		n -= min(k2*(n/k2) ,k2*a2);
		mxans += min(n/k1, a1);
		cout << mxans;
	}

	return 0;
}




















