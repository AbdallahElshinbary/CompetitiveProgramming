#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, x, d;
	while(cin >> n) {
		for(ll i=1; i<=10000; i++) {
			if(i*(i+1)/2 >= n) {
				d = i, x = (i*(i+1)/2) - n + 1;
				break;
			}
		}
		if(d % 2 == 0) {
			printf("TERM %d IS %d/%d\n", n, d+1-x, x);
		} else {
			printf("TERM %d IS %d/%d\n", n, x, d+1-x);
		}
	}

	return 0;
}
