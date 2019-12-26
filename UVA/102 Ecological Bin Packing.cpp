#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int arr[3][3];
	while(cin >> arr[0][0]) {
		cin >> arr[0][1] >> arr[0][2];
		for(int i=1; i<3; i++)
			for(int j=0; j<3; j++)
				cin >> arr[i][j];

		string ans = "BCG";
		string ans2;
		int cnt=INT_MAX, tmp;
		do {
			tmp = 0;
			for(int i=0; i<(int)ans.size(); i++) {
				for(int j=0; j<(int)ans.size(); j++) {
					if(i == j) continue;
					if(ans[i] == 'B') tmp+=arr[j][0];
					else if(ans[i] == 'C') tmp+=arr[j][2];
					else tmp+=arr[j][1];
				}
			}
			if(tmp < cnt)
				cnt = tmp, ans2=ans;

		} while(next_permutation(ans.begin(), ans.end()));

		cout << ans2 << " " << cnt << "\n";
	}

	return 0;
}
