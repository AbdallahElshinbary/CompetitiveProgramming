#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<int, int> arr[1000005];

int main() {
	int n, m;
	cin >> n;
	while(n--) {
		cin >> m;
		for(int i=0; i<m; i++) cin >> arr[i].first >> arr[i].second;

		string ans;
		int x, y, carry=0;
		for(int i=m-1; i>=0; i--) {
			x = arr[i].first + arr[i].second + carry;
			y = x%10, x/=10;
			carry = x;
			ans.push_back('0'+y);
		}
		if(carry) ans.push_back('0'+carry);

		for(int i=(int)ans.size()-1; i>=0; i--) cout << ans[i];
		cout << "\n";
		if(n) cout << "\n";
	}

	return 0;
}
