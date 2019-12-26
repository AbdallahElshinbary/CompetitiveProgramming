#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, x, d, ans=0;
	vector<int> odd, even;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		if(x%2 == 0) even.push_back(x);
		else odd.push_back(x);
	}
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());

	if(odd.size() > even.size()) {
		d = odd.size()-even.size()-1;
		for(int i=0; i<d; i++) ans += odd[i];
	} else if(odd.size() < even.size()) {
		d = even.size()-odd.size()-1;
		for(int i=0; i<d; i++) ans += even[i];
	}

	cout << ans;

	return 0;
}
