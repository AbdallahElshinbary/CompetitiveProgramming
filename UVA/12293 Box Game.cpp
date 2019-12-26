#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	while(cin >> n && n)
		cout << (((n&(n+1)) == 0) ? "Bob\n" : "Alice\n");

	return 0;
}
