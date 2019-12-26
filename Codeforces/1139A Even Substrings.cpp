#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, ans=0;
	string s;
	cin >> n >> s;
	for(int i=0; i<n; i++)
		if((s[i]-'0')%2 == 0)
			ans += i+1;
	cout << ans;

	return 0;
}
