#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s,a,b;
	map<string, string> mp;
	while(getline(cin, s)) {
		if(s == "") break;
		stringstream ss(s);
		ss >> a, ss >> b;
		mp[b] = a;
	}

	while(getline(cin, s)) {
		if(mp.find(s) == mp.end()) cout << "eh\n";
		else cout << mp[s] << "\n";
	}

	return 0;
}



