#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string a,b;
	map<string, bool> mp;

	while(cin >> a && a != "--") mp[a] = 1;
	while(cin >> a >> b) {
		bool ok=1;
		for(int i=0; i<(int)a.size(); i++) {
			if(a[i] == b[i]) continue;
			a[i] = b[i];
			if(!mp[a]) {ok=0; break;}
		}
		if(ok && mp[b]) cout << "Yes\n";
		else cout << "No\n";
	}


	return 0;
}

