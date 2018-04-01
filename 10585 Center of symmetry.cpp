#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

	int t,n;
	double x,y,cumx, cumy;
	pair<double, double> arr[10005];
	cin >> t;
	while(t--) {
		cumx = cumy = 0;
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> x >> y;
			cumx += x, cumy += y;
			arr[i] = {x,y};
		}
		cumx /= n, cumy /= n;

		bool check = true;
		for(int i=0; i<n; i++) {
			if(find(arr, arr+n, make_pair(cumx*2-arr[i].first, cumy*2-arr[i].second)) == arr+n) {
				check = false;
				break;
			}
		}
		cout << (check ? "yes\n" : "no\n");
	}

    return 0;
}

