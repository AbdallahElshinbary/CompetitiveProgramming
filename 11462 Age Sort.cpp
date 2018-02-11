#include <bits/stdc++.h>
using namespace std;

const int LIMIT=2000005;
int arr[LIMIT];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while(cin >> n && n != 0) {
		for(int i=0; i<n; i++)
			cin >> arr[i];
		sort(arr, arr+n);
		for(int i=0; i<n-1; i++)
			cout << arr[i] << " ";
		cout << arr[n-1] << endl;

	}
	return 0;
} 
