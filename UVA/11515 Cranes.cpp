#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


double diff(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
	int t,n,ans=0;
	double x[20], y[20], r[20];
	cin >> t;
	while(t--) {
		cin >> n;

		for(int i=0; i<n; i++) cin >> x[i] >> y[i] >> r[i];

		bool flag;
		int temp_ans;
		ans = 0;
		for(int i=1; i<(1 << n); i++) {
			vector<int> temp;
			temp_ans=0;
			for(int j=0; j<n; j++) {
				if(i & (1 << j)) {
					flag = true;
					for(int k : temp) {
						if(r[k]+r[j] >= diff(x[k], y[k], x[j], y[j])) {
							flag=false;
							break;
						}
					}
					if(flag) {
						temp.push_back(j);
						temp_ans += (r[j]*r[j]);
					}
				}
			}
			ans = max(ans, temp_ans);
		}
		cout << ans << "\n";
	}

	return 0;
}
