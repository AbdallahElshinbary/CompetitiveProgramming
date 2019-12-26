#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string a,b;
int s1,s2,t=0;
int idx, shift;
int dp[100][100];

int go(int x, int y) {
	if(x == s1) return s2-y;
	if(y == s2) return s1-x;

	int &ret = dp[x][y];
	if(ret != -1) return ret;

	if(a[x] == b[y]) return ret = go(x+1,y+1);

	int o1 = 1 + go(x, y+1);	//insert
	int o2 = 1 + go(x+1, y);	//delete
	int o3 = 1 + go(x+1, y+1);	//replace

	return ret = min(o1, min(o2,o3));
}

void go2(int x, int y) {
	if(x == s1) {
		for(int i=0; i<s2-y; i++) printf("%d Insert %d,%c\n", ++idx, x+i+shift+1, b[y+i]);
		shift += s2-y;
		return;
	}
	if(y == s2) {
		for(int i=0; i<s1-x; i++) {printf("%d Delete %d\n", ++idx, x+i+shift+1); shift--;}
		return;
	}

	if(a[x] == b[y]) {
		go2(x+1,y+1);
		return;
	}

	int o1 = 1 + go(x, y+1);	//insert
	int o2 = 1 + go(x+1, y);	//delete
	int o3 = 1 + go(x+1, y+1);	//replace
	int opt = go(x,y);

	if(opt == o1) {
		printf("%d Insert %d,%c\n", ++idx, x+shift+1, b[y]); shift++;
		go2(x, y+1);
	} else if(opt == o2) {
		printf("%d Delete %d\n", ++idx, x+shift+1); shift--;
		go2(x+1, y);
	} else{
		printf("%d Replace %d,%c\n", ++idx, x+shift+1, b[y]);
		go2(x+1, y+1);
	}
}

int main() {
	while(getline(cin, a) && getline(cin, b)) {
		s1 = (int)a.size(), s2 = (int)b.size();

		memset(dp, -1, sizeof dp);
		idx = shift = 0;
		if(t) printf("\n");
		printf("%d\n", go(0,0));
		go2(0,0);
		t++;
	}

	return 0;
}
