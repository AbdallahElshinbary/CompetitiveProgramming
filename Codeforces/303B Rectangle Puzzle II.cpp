#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m,x,y,a,b,g,f;
	scanf("%d %d %d %d %d %d",&n,&m,&x,&y,&a,&b);
	g = __gcd(a,b);
	a/=g, b/=g;
	f = min(n/a, m/b);
	a*=f, b*=f;

	int x1=0,y1=0,x2=x1+a,y2=y1+b;
	int cx=ceil(x2/2.0), cy=ceil(y2/2.0);
	int xx = min(max(x-cx, 0), n-x2);
	int yy = min(max(y-cy, 0), m-y2);
	x1 += xx, x2 += xx, y1 += yy, y2 += yy;
	printf("%d %d %d %d", x1,y1,x2,y2);

	return 0;
}
