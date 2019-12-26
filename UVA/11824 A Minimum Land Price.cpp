#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t, n, cnt;
	ll sum;
	vector<int> v;
	bool ex;
	cin >> t;
	while(t--) {
		cnt = 1, sum = 0;
		ex = false;
		while(cin >> n && n) v.push_back(n);
		sort(v.begin(), v.end(), greater<int>());
		for(int x : v) {
			sum += (2 * powl(x, cnt)), cnt++;
			if(sum > 5*1e6) {
				cout << "Too expensive\n";
				ex = true;
				break;
			}
		}
		if(!ex) cout << sum << "\n";
		v.clear();
	}

	return 0;
}