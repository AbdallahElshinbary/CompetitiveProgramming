#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string a,b,m[2];
int s1,s2,shift=0;
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
		for(int i=0; i<toAdd; i++) printf("INSERT %d %c\n", i+x+shift+1, b[i+y]);
		shift += toAdd;
		return;
	}
	if(y == s2) {
		int toDel = s1-x;
		for(int i=0; i<toDel; i++) {printf("DELETE %d\n", i+x+shift+1); shift--;}
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
		printf("INSERT %d %c\n", x+shift+1, b[y]); shift++;
		trace(x, y+1);
	} else if(opt == op2) {
		printf("DELETE %d\n", x+shift+1); shift--;
		trace(x+1, y);
	} else {
		printf("REPLACE %d %c\n", x+shift+1, b[y]);;
		trace(x+1, y+1);
	}
}


int main() {
	cin >> a >> b;
	s1 = (int)a.size(), s2 = (int)b.size();
	memset(dp, -1, sizeof dp);
	printf("%d\n", go(0,0));
	trace(0,0);

	return 0;
}




























