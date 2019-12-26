#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
	int t,a,b,c,z;
	cin >> t;
	while(t--) {
		cin >> a >> b >> c;
		bool ok=false;
		for(int x=-100; x<=100; x++) {
			for(int y=-100; y<=100; y++) {
				z = a-x-y;
				if(x*y*z == b && (x*x)+(y*y)+(z*z) == c && x<y && x<z && y<z) {
					printf("%d %d %d\n", x,y,z);
					ok = true;
					break;
				}
			}
			if(ok) break;
		}
		if(!ok) printf("No solution.\n");
	}

	return 0;
}
