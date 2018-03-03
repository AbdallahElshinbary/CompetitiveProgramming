#include <bits/stdc++.h>
using namespace std;

int arr[10][30];

int main() {
	int t,n,m,cnt,edge[2];
	bool check;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin >> arr[i][j];

		check = true;
		set<pair<int,int> > ss;
		for(int j=0; j<m; j++) {
			cnt = 0;
			for(int i=0; i<n; i++) {
				if(arr[i][j] == 1) {
					cnt++;
					if(cnt > 2) {
						check = false;
						break;
					}
					edge[cnt-1] = i;
				}
				if(cnt == 2)
					ss.insert({edge[0], edge[1]});
			}
			if(!check)
				break;
		}
		if(ss.size() != m)	check=false;
		cout << (check ? "Yes\n" : "No\n");
	}

	return 0;
}

