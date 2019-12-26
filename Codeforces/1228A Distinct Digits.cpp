#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-6
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int f[10];
bool check(int n) {
	memset(f, 0, sizeof f);
	while(n) {
		if((++f[n%10]) == 2) return 0;
		n /= 10;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int l,r;
	cin >> l >> r;
	for(int i=l; i<=r; i++)
		if(check(i)) {cout << i; return 0;}
	cout << -1;

	return 0;
}



















