#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool mat[100][100];

int main() {
	int n;
	int arr[3];
	set<pair<pair<int, int>, int> > ss;
	while(cin >> n) {
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin >> mat[i][j];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(i != j && mat[i][j]) {
					for(int k=0; k<n; k++) {
						if(k != j && k != i && mat[j][k] && mat[k][i]) {
							arr[0]=i+1, arr[1]=j+1, arr[2]=k+1;
							if(is_sorted(arr, arr+3) || is_sorted(arr, arr+3, greater<int>()))
								ss.insert(make_pair(make_pair(arr[0],arr[1]),arr[2]));
						}
					}
				}
			}
		}
		for(auto x : ss)
				cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
		cout << "total:" << ss.size() << "\n\n";
		ss.clear();
	}

	return 0;
}
