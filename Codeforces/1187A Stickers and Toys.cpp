#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int T,n,s,t;
	cin >> T;
	while(T--) {
		cin >> n >> s >> t;
		cout << max(n-s, n-t) + 1 << "\n";
	}
	return 0;
}

