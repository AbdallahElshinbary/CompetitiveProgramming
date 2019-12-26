#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
	int t, g;
	ull ans;
	string s;
	cin >> t;
	int freq[28];
	vector<int> nu, de;
	for(int T=1; T<=t; T++) {
		cin >> s;
		memset(freq, 0, sizeof freq);
		for(char c : s) freq[c-'A']++;

		for(int x : freq) {
			if(x > 1) {
				for(int i=2; i<=x; i++) de.push_back(i);
			}
		}
		for(int i=2; i<=(int)s.size(); i++) nu.push_back(i);


		for(int i=0; i<(int)nu.size(); i++) {
			for(int j=0; j<(int)de.size(); j++) {
				g = __gcd(nu[i], de[j]);
				nu[i] /= g, de[j] /= g;
			}
		}

		ans = 1;
		for(int x : nu) ans *= x;
		cout << "Data set " << T << ": " << ans << "\n";
		nu.clear(); de.clear();
	}

	return 0;
}
