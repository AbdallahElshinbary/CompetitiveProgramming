#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n, sub_size, sum;
	int arr[15];
	set<vector<int>, greater<vector<int> > > nums;
	vector<int> temp;

	while(cin >> t >> n, (t | n)) {
		for(int i=0; i<n; i++)
			cin >> arr[i];

		cout << "Sums of " << t << ":\n";
		sub_size = pow(2,n);

		for(int i=0; i<sub_size; i++) {
			sum = 0;
			temp.clear();
			for(int j=0; j<n; j++) {
				if(i & (1 << j)) {
					sum += arr[j];
					temp.push_back(arr[j]);
				}
			}
			if(sum == t)
				nums.insert(temp);
		}
		if(nums.size() > 0) {
			for(auto v : nums) {
				cout << v[0];
				for(int x=1; x<v.size(); x++)
					cout << "+" << v[x];
				cout << "\n";
			}
		} else
			cout << "NONE\n";

		nums.clear();
	}

	return 0;
}

