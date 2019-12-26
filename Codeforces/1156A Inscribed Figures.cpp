#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,x,ans=0;
	int a[105];

	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];

	for(int i=1; i<n; i++) {
		if((a[i] == 2 && a[i-1] == 3) || (a[i] == 3 && a[i-1] == 2)) {cout << "Infinite"; return 0;}
		if((a[i] == 1 && a[i-1] == 3) || (a[i] == 3 && a[i-1] == 1)) ans += 4;
		if((a[i] == 2 && a[i-1] == 1) || (a[i] == 1 && a[i-1] == 2)) ans += 3;
	}

	for(int i=0; i<n-2; i++)
		if(a[i] == 3 && a[i+1] == 1 && a[i+2] == 2) ans--;

	cout << "Finite\n" << ans;

	return 0;
}
