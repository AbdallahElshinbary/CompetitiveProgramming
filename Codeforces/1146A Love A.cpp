#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	int n = (int)s.size();
	int a=0, b=0, c=0;
	for(char c : s) {
		if(c == 'a') a++;
		else b++;
	}

	if(b >= a) c = b-a+1;
	cout << n-c;

	return 0;
}
