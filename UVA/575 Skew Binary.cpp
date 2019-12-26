#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s;
	int k, ans;
	while(cin >> s && s != "0") {
		k = s.length(), ans=0;
		for(char c : s) {
			ans += (c-'0')*(pow(2, k)-1), k--;
		}
		cout << ans << "\n";
	}

	return 0;
}
