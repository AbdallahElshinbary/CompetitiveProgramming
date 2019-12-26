#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, c, ans=0, a[30]{}, b[30]{};
	string s;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> s;
		c = s[0]-'a';
		if(a[c] > b[c]) b[c]++;
		else a[c]++;
	}


	for(int i=0; i<26; i++) {
		ans += (a[i]*(a[i]-1))/2;
		ans += (b[i]*(b[i]-1))/2;
	}
	cout << ans;

	return 0;
}
