#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, q, v, h, sub_size, flow, cost, res;
	cin >> n;
	pair<int, int> arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i].first >> arr[i].second;
	sub_size = pow(2, n);
	cin >> q;
	for(int Q=1; Q<=q; Q++) {
		cin >> v >> h;
		res = INT_MAX;
		for(int i=0; i<sub_size; i++) {
			flow = cost = 0;
			for(int j=0; j<n; j++)
				if(i & (1 << j))
					flow += arr[j].first*h, cost += arr[j].second;
			if(flow >= v)
				res = min(res, cost);
		}


		cout << "Case " << Q << ": ";
		if(res == INT_MAX)
			cout << "IMPOSSIBLE\n";
		else
			cout << res << "\n";
	}

	return 0;
}

