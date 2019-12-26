#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n,k,x,ans;
	while(cin >> n && n) {
		multiset<int> s; ans=0;
		while(n--) {
			cin >> k;
			while(k--) {cin >> x; s.insert(x);}
			ans += *(--s.end()) - *(s.begin());
			s.erase(s.begin());
			s.erase(--s.end());
		}
		cout << ans << "\n";
	}

	return 0;
}



