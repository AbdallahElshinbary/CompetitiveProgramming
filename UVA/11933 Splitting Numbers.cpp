#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,a,b;
	while(cin >> n && n) {
		a = b = 0;
		bool f=1;
		for(int i=0; i<32; i++) {
			if(n & (1 << i)) {
				if(f) a |= (1 << i);
				else b |= (1 << i);
				f = !f;
			}
		}
		cout << a << " " << b << "\n";
	}

	return 0;
}



