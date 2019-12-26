#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,n,h;
	vector<string> v;
	cin >> t;
	while(t--) {
		cin >> n >> h;
		bitset<16> b;
		for(int i=0; i<(1 << n); i++) {
			b = (i^0);
			if(b.count() == (unsigned int) h) {
				b = i;
				v.push_back(b.to_string().substr(16-n, n));
			}
		}

		sort(v.begin(), v.end());
		for(auto x : v) cout << x << "\n";
		if(t) cout << "\n";
		v.clear();
	}

	return 0;
}
