#include <bits/stdc++.h>

using namespace std;

bool prime(int n) {
	if(n == 2) return true;
	if(n % 2 == 0 || n < 2) return false;

	for(int i=3; i*i<=n; i+=2)
		if(n%i == 0)
			return false;
	return true;
}

int main()
{
	map<char, int> mp;
	int t;
	string s;
	cin >> t;
	for(int tc=1; tc<=t; tc++){
		cin >> s;
		cout << "Case " << tc << ": ";
		for(char c : s)
			mp[c]++;

		bool check = false;
		for(auto it : mp)
			if(prime(it.second))
				check = true, cout << it.first;

		if(!check) cout << "empty";
		if(t) cout << "\n";

		mp.clear();
	}
	return 0;
}

