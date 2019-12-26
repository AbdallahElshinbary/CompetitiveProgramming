#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	scanf("%d", &n);
	if(n < 3) printf("-1");
	else if(n == 3) printf("210");
	else {
		int x=1;
		for(int i=0; i<n-1; i++) x = (x*10)%210;
		printf("1");
		for(int i=0; i<n-4; i++) printf("0");
		printf("%03d", 210-x);
	}

	return 0;
}
