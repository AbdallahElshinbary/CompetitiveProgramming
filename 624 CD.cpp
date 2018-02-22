#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,t, sub_size, sum, temp_sum;
	int arr[22];
	vector<int> vec, temp;

	while(cin >> n >> t) {
		for(int i=0; i<t; i++)
			cin >> arr[i];

		sum = -1;
		sub_size = pow(2, t);

		for(int i=0; i<sub_size; i++) {
			temp.clear();
			temp_sum = 0;

			for(int j=0; j<t; j++) {
				if(i & (1 << j)) {
					temp.push_back(arr[j]);
					temp_sum += arr[j];
				}
			}
			if(temp_sum <= n && temp_sum >= sum) {
				sum = temp_sum;
				vec = temp;
			}
		}
		for(int x : vec)
			cout << x << " ";
		cout << "sum:" << sum << "\n";
	}

	return 0;
}

