#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, l, carry, st;
	string x,y;
	cin >> t;
	while(t--) {
		cin >> x >> y;
		vector<int> v(200, 0);
		if(x.size() > y.size()) swap(x,y);
		l = y.size();
		for(int i=(int)x.size(); i<l; i++) x += "0";
		carry = 0;
		for(int i=0; i<l; i++) {
			v[i] += (x[i]-'0')+(y[i]-'0')+carry;
			carry = v[i]/10;
			v[i] %= 10;
		}
		for(int i=0; i<l; i++) {
			if(v[i] != 0) {
				st = i;
				break;
			}
			st = l;
		}
		for(int i=st; i<l; i++)
			cout << v[i];
		if(carry) cout << carry;
		cout << endl;
	}
	return 0;
}

