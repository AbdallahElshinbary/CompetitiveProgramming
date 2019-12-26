#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string toBase(int n, int b) {
	if(n == 0) return "0";

	string s;
	int x;
	while(n) {
		x = n%b, n /= b;
		s.push_back('0'+x);
	}
	int l = s.length();
	for(int i=0; i<l/2; i++) swap(s[i], s[l-i-1]);
	return s;
}

int main() {
	int k;
	cin >> k;
	for(int i=1; i<k; i++) {
		for(int j=1; j<k; j++) {
			cout << toBase(i*j, k) << " ";
		}
		cout << "\n";
	}
	return 0;
}
