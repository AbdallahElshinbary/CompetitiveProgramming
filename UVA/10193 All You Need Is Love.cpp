#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int string_to_int(string s) {
	int x = 0, p = s.length()-1;
	for(char c : s) {
		if(c == '1') x += pow(2, p);
		p--;
	}
	return x;
}

int main() {
	int n,x,y;
	string a,b;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a >> b;
		x = string_to_int(a);
		y = string_to_int(b);
		printf("Pair #%d: ", i);
		if(__gcd(x, y) == 1) printf("Love is not all you need!\n");
		else printf("All you need is love!\n");
	}

	return 0;
}
