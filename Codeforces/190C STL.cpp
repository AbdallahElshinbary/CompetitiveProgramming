#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s, ans;
int t;

void go() {
	if(cin >> s) {
		ans += s;
		if(s == "pair") ans += '<', go(), ans += ',', go(), ans += '>';
	}
	else t=1;
}

int main() {
	int n;
	cin >> n;
	go();
	if(t || cin >> s) cout << "Error occurred";
	else cout << ans;

	return 0;
}







