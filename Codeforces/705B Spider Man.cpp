#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, x, ans=0;
	cin >> n;
	while(n--) {
		cin >> x;
		ans ^= (x%2 == 0 ? 1 : 0);
		cout << (ans ? "1\n" : "2\n");
	}

	return 0;
}
