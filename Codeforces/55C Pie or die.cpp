#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m,k,a,b;
	cin >> n >> m >> k;
	while(k--) {
		cin >> a >> b;
		if(a-1 <= 4 || n-a <= 4 || b-1 <= 4 || m-b <= 4) {cout << "YES"; return 0;}
	}
	cout << "NO";

	return 0;
}
