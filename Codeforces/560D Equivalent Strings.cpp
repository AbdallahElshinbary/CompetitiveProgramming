#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(string a, string b) {
	if(a == b) return true;

	int l = a.length();
	if(l&1) return false;

	string a1 = a.substr(0, l/2);
	string b1 = b.substr(0, l/2);
	string a2 = a.substr(l/2, l/2);
	string b2 = b.substr(l/2, l/2);
	return (check(a1, b2) && check(a2, b1)) || (check(a1, b1) && check(a2, b2));
}

int main() {
	string a,b;
	cin >> a >> b;
	cout << (check(a,b) ? "YES" : "NO");

	return 0;
}
