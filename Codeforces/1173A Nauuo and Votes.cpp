#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int x,y,z,a,b;
	cin >> x >> y >> z;
	a = x-y+z;
	b = x-y-z;
	if(a == 0 && b == 0)
		cout << '0';
	else if(a > 0 && b > 0)
		cout << '+';
	else if(a < 0 && b < 0)
		cout << '-';
	else
		cout << '?';

	return 0;
}
