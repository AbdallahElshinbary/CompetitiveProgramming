#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int extended_eculid(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1, y = 0;
		return a;
	}

	int g = extended_eculid(b, a%b, y, x);
	y -= (a/b)*x;

	return g;
}

int main() {
	int a,b,x,y,g;
	while(cin >> a >> b) {
		g = extended_eculid(a,b,x,y);
		printf("%d %d %d\n", x, y, g);
	}

	return 0;
}
