#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	bool found;
	while(cin >> n && n) {
		found = false;
		for(int i=1; i<=100; i++) {
			for(int j=1; j<i; j++) {
				int x = i*i*i-j*j*j;
				if(x == n) {
					cout << i << " " << j << "\n";
					found = true;
					break;
				}
			}
			if(found) break;
		}
		if(!found) cout << "No solution\n";
	}

	return 0;
}
