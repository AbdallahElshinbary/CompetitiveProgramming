#include <bits/stdc++.h>
using namespace std;

int main() {
	int t=1, n, q, x, lower;
	while(cin >> n >> q && n !=0 && q != 0) {
		cout << "CASE# " << t << ":\n";
		vector<int> v;
		while(n--) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		while(q--) {
			cin >> x;
			lower = lower_bound(v.begin(), v.end(), x)-v.begin();
			if(v[lower] == x)
				cout << x << " found at " << lower+1 << "\n";
			else
				cout << x << " not found\n";
		}
		t++;
	}

	return 0;
}
