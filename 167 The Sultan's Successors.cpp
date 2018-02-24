#include <bits/stdc++.h>
using namespace std;

int board[8][8], row[8], t, m, temp;

bool place(int r, int c) {
	for(int i=0; i<c; i++)
		if(row[i] == r || abs(row[i]-r) == abs(i-c))
			return false;
	return true;
}

void backtrack(int c) {
	if(c == 8) {
		temp = 0;
		for(int i=0; i<8; i++)
			temp += board[row[i]][i];
		m = max(m, temp);
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
		m = 0;
		for(int i=0; i<8; i++)
			for(int j=0; j<8; j++)
				cin >> board[i][j];
		memset(row, 0, sizeof(row));
		backtrack(0);
		printf("%5d\n", m);
	}
	return 0;
}

