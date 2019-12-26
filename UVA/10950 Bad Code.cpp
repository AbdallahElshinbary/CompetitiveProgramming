#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, cnt=0;
map<char, string> mp;
char x;
string enc, y;

bool valid(string &s, int pos) {
	if(s.size() > enc.size()-pos) return false;
	return (enc.substr(pos, s.size()) == s);
}

void rec(string s, int pos) {
	if(pos == (int)enc.size()) {
		cnt++;
		cout << s << endl;
		return;
	}
	while(enc[pos] == '0') pos++;
	if(pos == (int)enc.size()) return;

	for(auto m: mp) {
		if(cnt == 100) return;
		if(valid(m.second, pos)) {
			rec(s+m.first, pos+m.second.size());
		}
	}
}

int main() {
	int TC=1;
	while(cin >> n && n) {
		cout << "Case #" << TC++ << "\n";
		for(int i=0; i<n; i++) {
			cin >> x >> y;
			mp[x] = y;
		}
		cin >> enc;

		cnt = 0;
		rec("", 0);

		cout << "\n";
		mp.clear();
	}
	return 0;
}
