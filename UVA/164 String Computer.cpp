#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string a,b,m[2];
int s1,s2,shift;
int dp[1005][1005];

int go(int x, int y) {
	if(x == s1) return s2-y;
	if(y == s2) return s1-x;

	int &ret = dp[x][y];
	if(ret != -1) return ret;

	if(a[x] == b[y])
		return ret = go(x+1, y+1);


	int op1 = 1 + go(x, y+1);		//insert
	int op2 = 1 + go(x+1, y);		//delete
	int op3 = 1 + go(x+1, y+1);		//replace

	return ret = min(op1, min(op2, op3));
}

void trace(int x, int y) {
	if(x == s1) {
		int toAdd = s2-y;
		for(int i=0; i<toAdd; i++) printf("I%c%02d", b[i+y], i+x+shift+1);
		shift += toAdd;
		return;
	}
	if(y == s2) {
		int toDel = s1-x;
		for(int i=0; i<toDel; i++) {printf("D%c%02d", a[i+x], i+x+shift+1); shift--;}
		return;
	}

	if(a[x] == b[y]) {
		trace(x+1, y+1);
		return;
	}

	int op1 = 1 + go(x, y+1);		//insert
	int op2 = 1 + go(x+1, y);		//delete
	int op3 = 1 + go(x+1, y+1);		//replace
	int opt = go(x,y);				//optimal

	if(opt == op1) {
		printf("I%c%02d", b[y], x+shift+1); shift++;
		trace(x, y+1);
	} else if(opt == op2) {
		printf("D%c%02d", a[x], x+shift+1); shift--;
		trace(x+1, y);
	} else {
		printf("C%c%02d", b[y], x+shift+1);;
		trace(x+1, y+1);
	}
}


int main() {
	while(cin >> a) {
		if(a == "#") break;
		cin >> b;
		s1 = (int)a.size(), s2 = (int)b.size(), shift=0;
		memset(dp, -1, sizeof dp);
		go(0,0);
		trace(0,0);
		printf("E\n");
	}

	return 0;
}
