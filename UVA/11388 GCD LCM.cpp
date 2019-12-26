#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,a,b,x;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &a, &b);
		x = __gcd(a,b);
		if(x == a && (a*b)/x == b) printf("%d %d\n", a, b);
		else printf("-1\n");
	}

	return 0;
}
