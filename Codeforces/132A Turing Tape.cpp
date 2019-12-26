#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s, x;
	getline(cin, s);

	int p=0, n;
	bitset<8> b;
	for(char c : s) {
		b = (int)c;
		x = b.to_string();
		reverse(x.begin(), x.end());
		bitset<8> b2(x);
		n = b2.to_ulong();
		cout << (p-n+256)%256 << "\n";
		p = n;
	}

	return 0;
}

