#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string x;
bool p,q,r,s,t;
pair<bool, int> a,b;

pair<bool, int> go(int i) {
	if(x[i] == 'p') return {p, i};
	if(x[i] == 'q') return {q, i};
	if(x[i] == 'r') return {r, i};
	if(x[i] == 's') return {s, i};
	if(x[i] == 't') return {t, i};

	auto a = go(i+1);
	if(x[i] == 'N') return {!a.first, a.second};

	auto b = go(a.second+1);
	if(x[i] == 'K') return {a.first && b.first, b.second};
	if(x[i] == 'A') return {a.first || b.first, b.second};
	if(x[i] == 'E') return {a.first == b.first, b.second};
	if(x[i] == 'C') return {!(a.first == 1 && b.first == 0), b.second};

	return {0,0};
}

int main() {
	bool ok;
	while(cin >> x && x[0] != '0') {
		ok = 1;
		for(int i=0; i<(1 << 5); i++) {
			p = i & (1 << 0);
			q = i & (1 << 1);
			r = i & (1 << 2);
			s = i & (1 << 3);
			t = i & (1 << 4);
			if(!go(0).first) {ok=0; break;}
		}
		cout << (ok ? "tautology\n" : "not\n");
	}

	return 0;
}
