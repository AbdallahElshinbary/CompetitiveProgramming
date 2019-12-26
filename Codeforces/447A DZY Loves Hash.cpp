#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int p, n, x, m;
	cin >> p >> n;
	bool bucket[p]{};
	for(int i=1; i<=n; i++) {
		cin >> x;
		m = x%p;
		if(bucket[m]) {cout << i; return 0;}
		bucket[m]=1;
	}
	cout << -1;

	return 0;
}

