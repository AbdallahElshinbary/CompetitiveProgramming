#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int x,n,m,s=0;
	cin >> x;

	char v[] = {'a', 'e', 'i', 'o', 'u'};

	for(int i=2; i*i<=x; i++) {
		if(x%i == 0) {
			n = i, m = x/i;
			if(n >= 5 && m >= 5) {
				for(int a=0; a<n; a++) {
					for(int b=0; b<m; b++) {
						cout << v[(b+s)%5];
					}
					s++;
				}
				return 0;
			}
		}
	}
	cout << -1;

	return 0;
}
