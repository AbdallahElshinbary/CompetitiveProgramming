#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,s;
	while(cin >> n >> s) {
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		deque<int> d;
		int sum = 0, length = INT_MAX;
		for(int i=0; i<n; i++) {
			sum += arr[i];
			d.push_back(arr[i]);
			while(sum >= s) {
				length = min(length, (int)d.size());
				sum -= d[0];
				d.pop_front();
			}
		}

		cout << ((length == INT_MAX) ? 0 : length) << "\n";
	}
	return 0;
}

