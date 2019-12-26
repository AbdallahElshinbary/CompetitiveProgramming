#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, p=0, m=1, i=0;
	cin >> n;
	bool vis[n]{};

	while(i < 1000) {
		p = (p+m), m++;
		if(p >= n) p %= n, i++;
		vis[p]=true;
	}

	bool res=true;
	for(auto x : vis) res &= x;

	cout << (res ? "YES" : "NO");

	return 0;
}






