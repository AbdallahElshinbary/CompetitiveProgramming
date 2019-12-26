#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	string s;
	bool ok;
	cin >> n;
	while(n--) {
		cin >> s;
		sort(s.begin(), s.end());

		ok = true;
		for(int i=1; i<(int)s.size(); i++)
			if(s[i]-s[i-1] != 1) {ok=false; break;}
		cout << (ok ? "Yes\n" : "No\n");
	}


	return 0;
}
