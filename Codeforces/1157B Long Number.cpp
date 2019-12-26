#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int mp[10];
	for(int i=1; i<=9; i++) cin >> mp[i];

	for(int i=0; i<(int)s.size(); i++) {
		if(mp[s[i]-'0'] > s[i]-'0') {
			while(mp[s[i]-'0'] >= s[i]-'0') {
				s[i] = mp[s[i]-'0']+'0';
				i++;
			}
			break;
		}
	}
	cout << s;

	return 0;
}
