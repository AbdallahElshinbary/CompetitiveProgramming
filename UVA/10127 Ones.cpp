#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, x, ans;
	while(cin >> n) {
		x = 0, ans = 0;
		while(++x) {
			ans = (ans*10 + 1) % n;
			if(ans == 0) {cout << x << "\n"; break;}
		}
	}

	return 0;
}
