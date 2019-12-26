#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,b,a,ac=0,x,i;
	cin >> n >> b >> a; ac=a;
	for(i=1; i<=n; i++) {
		cin >> x;
		if(b == 0 && ac == 0) break;
		if(x == 1) {
			if(ac == a) ac--;
			else {
				if(b) b--, ac++;
				else ac--;
			}
		}
		else {
			if(ac) ac--;
			else {
				if(!b) break;
				b--;
			}
		}
	}
	cout << i-1;

	return 0;
}
