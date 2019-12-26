#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t,a,b,cnt;
int row[8];

bool place(int x, int y) {
	for(int c=0; c<y; c++)
		if(row[c] == x || abs(x-row[c]) == abs(y-c)) return false;
	return true;
}

void rec(int c) {
	if(c == 8 && row[b]==a) {
		printf("%2d     ", cnt++);
		for(int i=0; i<8; i++) printf(" %d",row[i]+1);
		cout << endl;
		return;
	}

	for(int r=0; r<8; r++) {
		if(place(r, c)) {
			row[c]=r;
			rec(c+1);
		}
	}
}

int main() {
	cin >> t;
	while(t--) {
		cin >> a >> b;
		a--, b--;
		cnt=1;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		rec(0);
		if(t) printf("\n");
	}

	return 0;
}
