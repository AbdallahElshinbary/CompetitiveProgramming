#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	string s;
	cin >> n >> s;

	int mn[n];
	char c = 'z'+1;
	for(int i=n-1; i>=0; i--) {
		if(s[i] < c) {c = s[i], mn[i] = i;}
		else mn[i] = mn[i+1];
	}

	for(int i=0; i<n-1; i++) {
		if(s[mn[i+1]] < s[i]) {cout << "YES\n" << i+1 << " " << mn[i+1]+1 << endl; return 0;}
	}
	cout << "NO";

	return 0;
}
































