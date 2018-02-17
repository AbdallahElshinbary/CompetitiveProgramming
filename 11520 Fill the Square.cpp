#include <bits/stdc++.h>
using namespace std;

char arr[12][12];

bool check(int i, int j, char c) {
	if(arr[i+1][j] == c || arr[i-1][j] == c || arr[i][j+1] == c || arr[i][j-1] == c)
		return false;
	return true;
}

int main() {
	int T, n;
	cin >> T;
	for(int t=1; t<=T; t++) {
		cin >> n;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				cin >> arr[i][j];

		for(int i=0; i<=n+1; i++)
			arr[i][0] = arr[i][n+1] = '.';
		for(int j=0; j<=n+1; j++)
			arr[0][j] = arr[n+1][j] = '.';

		char c = 'A';
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				int x=0;
				if(arr[i][j] != '.')
					continue;
				while(!check(i, j, c+x))
					x++;
				arr[i][j] = c+x;
			}
		}

		cout << "Case " << t << ":\n";
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				cout << arr[i][j];
			}
			cout << "\n";
		}

	}
	return 0;
}

