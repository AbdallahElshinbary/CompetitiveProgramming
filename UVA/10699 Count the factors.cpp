#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, t, x;
	while(cin >> n && n) {
		t=n, x = 0;
		for(int i=2; i*i<n; i++) {
			if(n%i == 0) x++;
			while(n%i == 0) n/=i;
		}
		if(n > 1) x++;
		printf("%d : %d\n", t, x);
	}

	return 0;
}