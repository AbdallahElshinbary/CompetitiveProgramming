#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, c=1;
	int x=1, y=1;
	vector<pair<int, int> > v;
	cin >> n;
	while(n) {
		v.push_back(make_pair(x,y));
		n--, y++;
		if(!n) break;
		v.push_back(make_pair(x,y));
		n--, c++, x++;
	}
	cout << c << endl;
	for(auto vv : v) cout << vv.first << " " << vv.second << endl;

	return 0;
}
