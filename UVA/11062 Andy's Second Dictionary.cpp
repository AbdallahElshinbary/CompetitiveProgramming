#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s,t;
	set<string> ans;
	while(getline(cin, s)) {
		if(s.empty()) continue;
		for(int i=0; i<(int)s.size()-1; i++) {
			if(isalpha(s[i]) || s[i] == '-') t += tolower(s[i]);
			else {if(!t.empty()) ans.insert(t); t="";}
		}
		if(s.back() == '-') continue;
		if(isalpha(s.back())) {t += tolower(s.back()); ans.insert(t); t="";}
		else {if(!t.empty()) ans.insert(t); t="";}
	}
	for(string s : ans) cout << s << "\n";

	return 0;
}

