#include <bits/stdc++.h>
using namespace std;

int row[8], t, a, b, line;

bool place(int r, int c) {
	for(int i=0; i<c; i++)
		if(row[i] == r || abs(row[i]-r) == abs(i-c))
			return false;
	return true;
}

void backtrack(int c) {
	if(c == 8 && row[b] == a) {
		printf("%2d      ", ++line);
		cout << row[0]+1;
		for(int i=1; i<8; i++)
			cout << " " << row[i]+1;
		cout << "\n";
		return;
	}

	for(int r=0; r<8; r++) {
		if(place(r,c)) {
			row[c] = r;
			backtrack(c+1);
		}
	}

}

int main() {
	cin >> t;
	while(t--) {
		cin >> a >> b;
		a--,b--;
		line = 0;
		cout << "SOLN       COLUMN\n";
		cout << " #      1 2 3 4 5 6 7 8\n\n";
		memset(row, 0, sizeof(row));
		backtrack(0);
		if(t)
			cout << "\n";
	}
	return 0;
}

