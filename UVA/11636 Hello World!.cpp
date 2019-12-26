#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t=1, n, x, ans;
	while(cin >> n && n > 0) {
		x = 1, ans = 0;
		while(x < n) {
			if(2*x >= n) {
				ans++;
				break;
			}
			x *= 2, ans++;
		}
		printf("Case %d: %d\n", t++, ans);
	}

	return 0;
}
