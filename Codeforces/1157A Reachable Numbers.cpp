#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	map<int, bool> mp;
	cin >> n;
	mp[n]=1;

	while(1) {
		n++;
		while(n%10 == 0) n/=10;
		if(mp[n]) break;
		mp[n]=1;
	}

	cout << mp.size();

	return 0;
}
