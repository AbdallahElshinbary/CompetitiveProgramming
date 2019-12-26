#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s;
	for(int i=1; i<20000000; i++) s += to_string(i);

	int n;
	while(cin >> n) cout << s[n-1] << "\n";

	return 0;
}
