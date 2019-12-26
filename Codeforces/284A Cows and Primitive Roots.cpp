#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int p;
	cin >> p;
	if(p == 2) {cout << 1; return 0;}

	int x, ans=0;
	bool flag;
	for(int i=1; i<p; i++) {
		x = i, flag=1;
		if((i-1)%p == 0) continue;
		for(int j=1; j<p-2; j++) {
			x = (x*i) %p;
			if((x-1+p)%p == 0) {flag=0; break;}
		}
		if(flag) {
			x = (x*i) %p;
			if((x-1+p)%p == 0) ans++;
		}
	}
	cout << ans;

	return 0;
}

