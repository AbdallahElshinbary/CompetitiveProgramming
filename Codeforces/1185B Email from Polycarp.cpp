#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main() {
	int n,i,j;
	bool ok;
	char prev;
	string a,b;
	cin >> n;
	while(n--) {
		cin >> a >> b;

		ok = 1; prev='X';
		for(i=0, j=0; i<(int)a.size() && j<(int)b.size();) {
			if(a[i] == b[j]) prev=a[i], i++, j++;
			else {
				if(b[j] == prev) j++;
				else {ok=0; break;}
			}
		}
		if(i != (int)a.size()) ok=0;
		if(ok) {for(;j<(int)b.size(); j++) if(b[j] != b[j-1]) {ok=0; break;}}
		cout << (ok ? "YES\n" : "NO\n");
	}




	return 0;
}




























