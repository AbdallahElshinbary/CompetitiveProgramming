#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string a,b,m[2];
vector<string> va, vb;
int T=1,s1,s2;
int dp[1005][1005];

int go(int x, int y) {
	if(x == s1 || y == s2) return 0;

	int &ret = dp[x][y];
	if(ret != -1) return ret;

	if(va[x] == vb[y])
		return ret = 1 + go(x+1, y+1);

	return ret = max(go(x,y+1), go(x+1,y));
}


int main() {
	while(getline(cin, a) && getline(cin, b)) {
		if(a == "" || b == "") {printf("%2d. Blank!\n", T++); continue;}

		for(char &c : a) if(!isalnum(c)) c = ' ';
		for(char &c : b) if(!isalnum(c)) c = ' ';

		stringstream sa(a), sb(b);
		string s; va.clear(); vb.clear();
		while(sa >> s) va.push_back(s);
		while(sb >> s) vb.push_back(s);

		s1 = (int)va.size(), s2 = (int)vb.size();
		memset(dp, -1, sizeof dp);
		printf("%2d. Length of longest match: %d\n", T++, go(0,0));
	}

	return 0;
}
