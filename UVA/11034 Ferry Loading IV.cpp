#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,l,m,x,carry,ans;
	string y;
	cin >> t;
	while(t--) {
		queue<int> left, right;

		cin >> l >> m; l *= 100;
		for(int i=0; i<m; i++) {
			cin >> x >> y;
			if(y == "left") left.push(x);
			else right.push(x);
		}

		ans = 0;
		bool le=1;
		while(!left.empty() || !right.empty()) {
			carry = 0;
			if(le) {
				while(!left.empty()) {
					x = left.front();
					if(carry + x <= l) carry += x, left.pop();
					else break;
				}
			} else {
				while(!right.empty()) {
					x = right.front();
					if(carry + x <= l) carry += x, right.pop();
					else break;
				}
			}
			ans++, le = !le;
		}
		cout << ans << "\n";
	}

	return 0;
}
