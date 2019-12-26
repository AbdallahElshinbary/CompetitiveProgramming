#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
	ll S, D;
	while(cin >> S >> D) {
		if(D >= 1 && D <= S) {
			cout << S << "\n";
			continue;
		}
		ll s = 0, e = 1e15, m, x, l, r;
		ll offset = ((S-1)*S)/2;
		while(s <= e) {
			m = (s+e)/2;
			x = (m+S);
			l = 1 + ((x*(x+1))/2) - offset;
			r = l + x;
			if(D < l) e = m-1;
			else if(D > r) s = m+1;
			else {
				cout << x+1 << "\n";
				break;
			}
		}
	}

	return 0;
}
