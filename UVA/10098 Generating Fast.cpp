#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t;
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		sort(s.begin(), s.end());
		do {
			cout << s << "\n";
		} while(next_permutation(s.begin(), s.end()));
		cout << "\n";
	}

	return 0;
}
