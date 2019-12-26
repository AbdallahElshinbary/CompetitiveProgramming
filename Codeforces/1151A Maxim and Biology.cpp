#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, t, ans=1e9;
	string s, g = "ACTG";
	cin >> n >> s;
	for(int i=0; i<=n-4; i++) {
		t = 0;
		for(int j=i, k=0; k<4; j++,k++) {
			if(s[j] > g[k]) t += min(s[j]-g[k], g[k]-'A'+1+'Z'-s[j]);
			else t += min(g[k]-s[j], 'Z'-g[k]+1+s[j]-'A');
		}
		ans = min(ans, t);
	}
	cout << ans;

	return 0;
}

