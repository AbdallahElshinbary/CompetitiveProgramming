#include <bits/stdc++.h>

using namespace std;

int main()
{
	string x,y;
	int lx, ly, carry, idx, st;
	int v[601];
	while(cin >> x >> y) {
		memset(v, 0, 601*4);
		lx = (int)x.size(), ly = (int)y.size();
		idx = st = 0;
		for(int i=lx-1; i>=0; i--) {
			for(int j=ly-1; j>=0; j--, idx++) {
				v[idx] += (int(x[i]-'0')*int(y[j]-'0'))+carry;
				carry = v[idx]/10;
				v[idx] = v[idx]%10;
			}
			v[idx] += carry;
			st++;
			idx = st;
			carry = 0;
		}

		bool check = false;
		for(int i=600; i>=0; i--) {
			if(v[i] != 0) check = true;
			if(check)
				cout << v[i];
		}
		if(!check) cout << "0";
		cout << endl;
	}

	return 0;
}



