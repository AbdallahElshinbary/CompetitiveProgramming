#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll q,n,a,b;
	cin >> q;
	while(q--) {
		cin >> n >> a >> b;
		if(2*a <= b) cout << n*a << "\n";
		else {
			if(n%2 == 0) cout << (n/2)*b << "\n";
			else cout << (n/2)*b + a << "\n";
 		}
	}

	return 0;
}
