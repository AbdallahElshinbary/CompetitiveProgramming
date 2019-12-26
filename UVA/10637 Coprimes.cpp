#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int s, t, T;
vector<int> v;

void solve(int sum, int n, int prod, int prev) {
	if(n == t) {
		if(sum != s) return;
		printf("%d", v[0]);
		for(int i=1; i<(int)v.size(); i++) printf(" %d", v[i]);
		printf("\n");
		return;
	}

	int tmp;
	for(int i=prev; i<=(s-sum); i++) {
		if(sum + i > s) break;
		tmp = __gcd(prod, i);
		if(tmp != 1) continue;
		v.push_back(i);
		solve(sum+i, n+1, i*prod, i);
		v.pop_back();
	}
}

int main() {
	cin >> T;
	for(int TT=1; TT<=T; TT++) {
		cin >> s >> t;
		printf("Case %d:\n", TT);
		solve(0, 0, 1, 1);
	}

	return 0;
}
