#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s, a, d, f;
	int pd, pe, b;
	cin >> s;
	pd = s.find('.');
	pe = s.find('e');
	a = s.substr(0, pd);
	d = s.substr(pd+1, pe-pd-1);
	b = stoi(s.substr(pe+1));

	if(b == 0 && d == "0") {cout << a << "\n"; return 0;}

	if((int)d.length() <= b) {
		cout << a+d;
		for(int i=0; i<b-(int)d.length(); i++) cout << '0';
		cout << "\n";
	}
	else {
		f = a+d;
		f.insert(a.length()+b, ".");
		cout << f;
	}

	return 0;
}












