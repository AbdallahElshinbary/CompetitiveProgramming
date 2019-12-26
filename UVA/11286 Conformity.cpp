#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,x,mx,ans;
	map<vector<int>, int> mp;

	while(cin >> n && n) {
		for(int i=0; i<n; i++) {
			vector<int> v;
			for(int j=0; j<5; j++) {cin >> x; v.push_back(x);}
			sort(v.begin(), v.end());
			mp[v]++;
		}

		mx = ans = 0;
		for(auto m : mp) {
			if(m.second > mx) {mx = m.second, ans = m.second;}
			else if(m.second == mx) {ans += mx;}
		}
		cout << ans << "\n";
		mp.clear();
	}

	return 0;
}



