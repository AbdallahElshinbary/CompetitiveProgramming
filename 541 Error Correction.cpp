#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin >> n && n != 0) {
		vector<int> row, col;

		int arr[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin >> arr[i][j];

		int sum_row, sum_col;
		for(int i=0; i<n; i++) {
			sum_row = sum_col = 0;
			for(int j=0; j<n; j++) {
				sum_row += arr[i][j];
				sum_col += arr[j][i];
			}
			if(sum_row % 2 != 0) row.push_back(i+1);
			if(sum_col % 2 != 0) col.push_back(i+1);
		}

		if(row.size() == 1 && col.size() == 1)
			cout << "Change bit (" << row[0] << "," << col[0] << ")\n";
		else if(row.size() != col.size() || row.size() > 1 || col.size() > 1)
			cout << "Corrupt\n";
		else
			cout << "OK\n";
	}
	return 0;
}