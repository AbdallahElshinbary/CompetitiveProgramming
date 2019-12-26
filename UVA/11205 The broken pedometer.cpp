#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,p,n;
	bool flag;
	cin >> t;
	while(t--) {
		cin >> p >> n;
		bitset<16> arr[n];
		for(int i=0; i<n; i++) {
			for(int x=0; x<p; x++) {
				cin >> flag;
				if(flag) arr[i].set(x);
			}
		}
		set<string> ss;
		int ans = 50;
		for(int i=0; i<(1 << p); i++) {
			bitset<16> b(i);
			for(int j=0; j<n; j++) {
				ss.insert((b&arr[j]).to_string());
			}
			if((int)ss.size() == n) ans = min(ans, (int)b.count());
			ss.clear();
		}
		cout << ans << endl;
	}

	return 0;
}
