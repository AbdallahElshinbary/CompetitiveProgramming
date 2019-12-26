#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
	int de[13];
	de[1] = 0;
	de[2] = 1;

	for(int i=3; i<13; i++)
		de[i] = (i-1) * (de[i-1] + de[i-2]);

	ull fact[13];
	fact[1] = 1;
	for(int i=2; i<13; i++)
		fact[i] = i*fact[i-1];

	int t,n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << de[n] << "/" << fact[n] << "\n";
	}

	return 0;
}
