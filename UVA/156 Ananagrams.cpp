#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s, o;
	map<string, int> mp;
	map<string, string> org;
	vector<string> ans;
	while(cin >> s && s != "#") {
		o = s;
		for(char &c : s) c = tolower(c);
		sort(s.begin(), s.end());
		org[s] = o; mp[s]++;
	}

	for(auto m : mp) {
		if(m.second == 1) ans.push_back(org[m.first]);
	}
	sort(ans.begin(), ans.end());
	for(string s : ans) cout << s << "\n";

	return 0;
}

