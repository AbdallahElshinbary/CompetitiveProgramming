#include <bits/stdc++.h>
using namespace std;

int t,d,n,x,y,p, max_p, res_x, res_y;
int arr[1025][1025];

void calc(int x, int y, int p) {
	int min_x = max(0, x-d),
		max_x = min(1024, x+d),
		min_y = max(0, y-d),
		max_y = min(1024, y+d);

	for(int i=min_x; i<=max_x; i++)
		for(int j=min_y; j<=max_y; j++)
			arr[i][j] += p;
}

int main() {
	cin >> t;
	while(t--) {
		cin >> d >> n;

		for(int i=0; i<=1024; i++)
			for(int j=0; j<=1024; j++)
				arr[i][j] = 0;

		for(int i=0; i<n; i++) {
			cin >> x >> y >> p;
			calc(x,y,p);
		}

		max_p = -1;
		for(int i=0; i<=1024; i++)
			for(int j=0; j<=1024; j++)
				if(arr[i][j] > max_p)
					max_p = arr[i][j], res_x=i, res_y=j;

		cout << res_x << " " << res_y << " " << max_p << "\n";
	}

	return 0;
}

