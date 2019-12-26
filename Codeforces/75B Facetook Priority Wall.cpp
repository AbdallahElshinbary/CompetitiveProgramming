#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s,x,a,b,c,d;
	int n;
	map<string, int> mp1;
	multimap<int, string, greater<int> > mp2;
	cin >> s >> n; cin.ignore();
	while(n--) {
		getline(cin, x);
		stringstream ss(x);
		ss >> a;
		ss >> c;
		if(c == "likes") ss >> b;
		else ss >> d, ss >> b;
		b.pop_back(), b.pop_back();

		if(a == s) mp1[b] += (c == "posted" ? 15 : (c == "commented" ? 10 : 5));
		else if(b == s) mp1[a] += (c == "posted" ? 15 : (c == "commented" ? 10 : 5));
		else {
			if(mp1.find(a) == mp1.end()) mp1[a]=0;
			if(mp1.find(b) == mp1.end()) mp1[b]=0;
		}
	}

	for(auto x : mp1) mp2.insert({x.second, x.first});
	for(auto x : mp2) {cout << x.second << "\n";}


	return 0;
}



