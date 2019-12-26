#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,x;
	string s;
	bool ok;
	cin >> n >> s;
	for(int i=0; i<=n; i++) {
		x = i, ok = 1;
		for(char c : s) {
			if(c == '+') x++;
			else x--;
			if(x < 0) {ok=0; break;}
		}
		if(ok) {x = i; break;}
	}

	for(char c : s) {
		if(c == '+') x++;
		else x--;
	}
	cout << x;

	return 0;
}
