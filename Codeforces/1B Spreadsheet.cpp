#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 1000006;
string C[MAX_N];

int main() {
	int x=0, t=1;
	int st[7];
	string s = "A";

	for(int i=1; i<MAX_N; i++) {
		C[i] = s;

		s.back()++;
		if(s.back() > 'Z') {
			x = s.length()-1;
			while(x >= 0) {
				s[x]++;
				if(s[x] > 'Z') s[x]='A';
				else break;
				x--;
			}
		}

		if(x < 0) {
			st[++t] = i+1;
			x = s.length();
			s = "";
			for(int i=0; i<=x; i++) s += "A";
		}
	}
	st[1] = 1;
	st[6] = MAX_N;

	int n,i,sz;
	string a,b,c;
	cin >> n;
	while(n--) {
		cin >> s;
		sz = (int)s.size();
		a = b = c = "";

		for(i=0; i<sz; i++) {
			if(!isalpha(s[i])) break;
			a += s[i];
		}
		for(;i<sz; i++) {
			if(!isdigit(s[i])) break;
			b += s[i];
		}
		if(i < sz) {
			for(i=i+1; i<sz; i++)
				c += s[i];
		}

		if(c.empty()) {
			int p = lower_bound(C+st[a.size()], C+st[a.size()+1], a) - C;
			cout << "R" << b << "C" << p << "\n";
		} else {
			cout << C[stoi(c)] << b << "\n";
		}
	}

	return 0;
}











