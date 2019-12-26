#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int n) {
	int x = 0;
	while(n) {
		x += n%10, n/=10;
	}
	return (x%4 == 0);
}

int main() {
	int a;
	cin >> a;
	for(int i=a; ;i++) if(check(i)) {cout << i; break;}

	return 0;
}







