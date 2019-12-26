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

	int n,x,a=0,b=0;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		if(x&1) a++; else b++;
	}
	cout << min(a,b);


	return 0;
}


















