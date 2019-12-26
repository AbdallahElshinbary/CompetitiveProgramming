#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	bitset<32> b;
	int n;
	while(cin >> n && n) {
		b = n;
		string s = b.to_string();
		while(s[0] == '0') s.erase(0, 1);
		cout << "The parity of "<< s << " is " << b.count() << " (mod 2).\n";
	}

	return 0;
}
