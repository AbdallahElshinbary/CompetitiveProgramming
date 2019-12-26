#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int a,b,r;
	cin >> a >> b >> r;
	cout << (2*r > min(a,b) ? "Second" : "First");

	return 0;
}
