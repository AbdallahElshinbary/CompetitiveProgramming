#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t, c, r, i;
	vector<int> ans;
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> c >> r;
		c -= r;
		if(c == 0) ans.push_back(0);
		for(i=1; i*i<c; i++) {
			if(c%i == 0) {
				if(i > r) ans.push_back(i);
				if(c/i > r) ans.push_back(c/i);
			}
		}
		if(i*i == c && i > r) ans.push_back(i);
		sort(ans.begin(), ans.end());

		printf("Case #%d:", T);
		for(int x : ans) printf(" %d", x);
		printf("\n");

		ans.clear();
	}
	return 0;
}
