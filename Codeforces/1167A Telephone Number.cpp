#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,n;
	string s;
	bool ok;

	cin >> t;
	while(t--) {
		cin >> n >> s; ok=0;
		reverse(s.begin(), s.end());

		for(int i=0; i<n; i++) {
			if(s[i] == '8' && i >= 10) {ok=1; break;}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}

	return 0;
}
