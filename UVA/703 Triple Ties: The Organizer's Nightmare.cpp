#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
	int n;
	while(cin >> n) {
		set<pair<int, pair<int, int> > > cycles;
		set<pair<int, pair<int, int> > > draws;

		bool arr[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin >> arr[i][j];


		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(i == j) continue;
				if(arr[i][j]) {
					for(int k=0; k<n; k++) {
						if(arr[j][k] && arr[k][i] && ((i>j && i>k && j>k) || (i<j && i<k && j<k)))
							cycles.insert(make_pair(i+1, make_pair(j+1, k+1)));
					}
				} else if(!arr[i][j] && !arr[j][i]) {
					for(int k=0; k<n; k++) {
						if(j == k) continue;
						if(k!=i && !arr[j][k] && !arr[k][j] && !arr[k][i] && !arr[i][k] && i<j && i<k && j<k)
							draws.insert(make_pair(i+1, make_pair(j+1, k+1)));
					}
				}
			}
		}

		cout << cycles.size() + draws.size() << endl;
		for(auto x : draws)
			cycles.insert(x);
		for(auto x : cycles)
			cout << x.first << " " << x.second.first << " " << x.second.second << endl;
	}

	return 0;
}
