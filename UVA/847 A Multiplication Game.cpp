#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, p;
	bool f;
	while(cin >> n) {
		p=1, f=1;
		while(p < n) {
			if(f) p *= 9;
			else p *= 2;
			f = !f;
		}
		cout << (f ? "Ollie wins.\n" : "Stan wins.\n");
	}

	return 0;
}
