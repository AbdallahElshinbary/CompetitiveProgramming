#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;

	while(cin >> n >> m && n != 0 && m != 0) {
		int heads[n], knights[m];
		for(int i=0; i<n; i++)
			cin >> heads[i];
		for(int i=0; i<m; i++)
			cin >> knights[i];

		sort(heads, heads+n);
		sort(knights, knights+m);

		int head_index=0, cost=0;
		for(int i=0; i<m; i++) {
			if(head_index == n)
				break;
			if(knights[i] >= heads[head_index]) {
				cost += knights[i];
				head_index++;
			}
		}

		if(head_index == n)
			cout << cost << "\n";
		else
			cout << "Loowater is doomed!\n";
	}
	return 0;
}


