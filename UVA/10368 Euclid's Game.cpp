#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-6
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int go(ll a, ll b) {
	if(b == 0) return 0;
	if(a/b > 1) return 1;	//has multiple choices
	return go(b, a-b)+1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a,b;
	while(cin >> a >> b && a+b) {
		if(a < b) swap(a,b);
		cout << (go(a,b)&1 ? "Stan wins\n" : "Ollie wins\n");
	}

	return 0;
}





















