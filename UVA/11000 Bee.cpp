#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll male, female, n;
	while(cin >> n && n >= 0) {
		male=0, female=1;
		while(n--) {
			int temp = male;
			male += female;
			female = temp + 1;
		}
		cout << male << " " << male+female << "\n";
	}

	return 0;
}
	