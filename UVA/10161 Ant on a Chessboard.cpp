#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, x, a, b, c, d;
	while(cin >> n && n) {
		x = sqrt(n);
		if(x%2 == 1 && x*x == n) {
			cout << 1 << " " << x << "\n";
			continue;
		}
		if(x%2 == 1) a=x, b=x+2;
		else a=x-1, b=x+1;

		if((b*b) - b + 1 <= n) cout << ((b*b) - n + 1) << " " << b << "\n";
		else {
			c = (a*a)+1;
			if(n - c <= a) {
				cout << (n - c + 1) << " " << (a+1) << "\n";
			} else {
				d = c+a;
				if(n - d <= a) {
					cout << a+1 << " " << (a+1-(n-d)) << "\n";
				} else {
					cout << a+2 << " " << (n-d-a) << "\n";
				}
			}
		}
	}

	return 0;
}
