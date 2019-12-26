#include <bits/stdc++.h>
using namespace std;

int main() {
	string s,t;
	while(cin >> s >> t) {
		int idx = 0, cnt = 0;
		for(char c : t) {
			if(idx == s.size()) break;
			if(c == s[idx])
				cnt++, idx++;
		}
		if(cnt == s.size())
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}



