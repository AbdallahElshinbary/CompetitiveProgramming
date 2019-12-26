#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t,n,m,x,ans;
bool wd[1025];

int go(int l, int r) {
	if(l == r) return wd[l];
	int a = go(l, (r+l)/2);
	int b = go((r+l)/2+1, r);
	if(a && b) return 1;
	if(a || b) ans++;
	return 0;
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n >> m;
		memset(wd, 0, sizeof wd); ans=0;
		for(int i=0; i<m; i++) {cin >> x; wd[--x]=1;}
		go(0, (1<<n) - 1);
		cout << ans << "\n";
	}

	return 0;
}







