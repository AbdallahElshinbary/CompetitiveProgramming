#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, x;
	while(cin >> n && n) {
		x = sqrt(n);
		cout << (x*x == n ? "yes\n" : "no\n");
	}

	return 0;
}
