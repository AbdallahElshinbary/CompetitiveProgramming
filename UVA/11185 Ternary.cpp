#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	while(cin >> n && n >= 0) {
		if(n == 0) {cout << "0\n"; continue;}
		string ans;
		while(n) {
			ans.push_back('0' + n%3);
			n /= 3;
		}
		for(int i=(int)ans.size()-1; i>=0; i--) cout << ans[i];
		cout << "\n";
	}

	return 0;
}
