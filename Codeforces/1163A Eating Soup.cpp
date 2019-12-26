#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m;
	cin >> n >> m;
	if(m == 0) cout << 1;
	else if(m > n/2) cout << n-m;
	else cout << m;

	return 0;
}
