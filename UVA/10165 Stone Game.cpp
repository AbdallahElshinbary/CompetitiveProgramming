#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, x, ans;
	while(cin >> n && n) {
		ans = 0;
		for(int i=0; i<n; i++) {cin >> x; ans ^= x;}
		cout << (ans == 0 ? "No\n" : "Yes\n");
	}
	return 0;
}
