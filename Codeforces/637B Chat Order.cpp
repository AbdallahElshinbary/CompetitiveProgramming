#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	map<string, bool> mp;
	string arr[200005];
	int n;
	string s;
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=n-1; i>=0; i--) {
		if(mp[arr[i]]) continue;
		mp[arr[i]] = 1;
		cout << arr[i] << "\n";
	}

	return 0;
}



