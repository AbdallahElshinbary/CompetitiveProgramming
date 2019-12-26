#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,q,l,x,lower,upper;
	vector<int> v;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> l;
		v.push_back(l);
	}
	cin >> q;
	while(q--) {
		cin >> x;
		lower = lower_bound(v.begin(), v.end(), x)-v.begin()-1;
		upper = upper_bound(v.begin(), v.end(), x)-v.begin();

		if(lower < 0)
			cout << "X ";
		else
			cout << v[lower] << " ";

		if(upper == n)
			cout << "X\n";
		else
			cout << v[upper] << "\n";
	}

	return 0;
}
