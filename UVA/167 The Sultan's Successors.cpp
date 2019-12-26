#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int row[8];
int board[8][8];
int ans, temp;

bool place(int r, int c) {
	for(int prev=0; prev<c; prev++)
		if(row[prev] == r || abs(row[prev]-r) == abs(prev-c))
			return false;
	return true;
}

void solve(int c) {
	if(c == 8) {
		temp = 0;
		for(int i=0; i<8; i++)
			temp += board[row[i]][i];
		ans = max(ans, temp);
	}
	for(int r=0; r<8; r++) {
		if(place(r, c))
			row[c] = r, solve(c+1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		ans = 0;
		for(int i=0; i<8; i++)
			for(int j=0; j<8; j++)
				cin >> board[i][j];
		solve(0);
		cout << setw(5) << ans;
		cout << "\n";
	}

	return 0;
}
