#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,r=0,b=0;
	char c;

	cin >> n;
	while(n--) {
		cin >> c;
		if(c == '(') {
			if(r > b) {b++; cout << 1;}
			else {r++; cout << 0;}
		} else {
			if(r > b) {r--; cout << 0;}
			else {b--; cout << 1;}
		}
	}


	return 0;
}
