#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	cout << ((n&1) ? 0 : (ll)powl(2, n/2));

	return 0;
}
