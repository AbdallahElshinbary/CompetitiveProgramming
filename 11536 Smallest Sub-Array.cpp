#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
map<int, int> freq;

bool check(int k) {
	for(int x=1; x<=k; x++)
		if(freq[x] < 1)
			return false;
	return true;
}

int main() {
	int T,n,m,k;
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	cin >> T;
	for(int t=1; t<=T; t++) {
		cin >> n >> m >> k;

		for(int i=3; i<n; i++)
			arr[i] = ((arr[i-1] + arr[i-2] + arr[i-3])%m) + 1;

		deque<int> d;
		int cnt = INT_MAX;
		bool found = false;

		for(int i=0; i<n; i++) {
			d.push_back(arr[i]);
			if(arr[i] > k)	continue;
			freq[arr[i]]++;
			if(check(k)) {
				found = true;
				while(true) {
					cnt = min(cnt, (int)d.size());
					if(d[0] <= k) {
						freq[d[0]]--;
						if(freq[d[0]] == 0) break;
					}
					d.pop_front();
				}
				d.pop_front();
			}
		}

		cout << "Case " << t << ": ";
		if(found)
			cout << cnt << "\n";
		else
			cout << "sequence nai\n";

		freq.clear();
	}

	return 0;
}

