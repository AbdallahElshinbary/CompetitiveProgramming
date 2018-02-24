#include <bits/stdc++.h>
using namespace std;

int arr[5];

bool solve(int curr, int next) {
	if(next == 5)
		return (curr == 23);

	if(solve(curr+arr[next], next+1)) return true;
	if(solve(curr-arr[next], next+1)) return true;
	if(solve(curr*arr[next], next+1)) return true;

	return false;
}

int main() {
	while(true) {
		for(int i=0; i<5; i++)
			cin >> arr[i];
		sort(arr, arr+5);
		if(arr[0] == 0) break;

		bool check = false;
		do {
			if(solve(arr[0], 1)) {
				check = true;
				cout << "Possible\n";
				break;
			}
		} while(next_permutation(arr, arr+5));
		if(!check)
			cout << "Impossible\n";
	}
	return 0;
}
