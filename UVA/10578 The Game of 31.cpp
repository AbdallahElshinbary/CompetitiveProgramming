#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[5][5][5][5][5][5];
int num[7];

int solve(int sum) {
	int &ret = dp[num[1]][num[2]][num[3]][num[4]][num[5]][num[6]];
	if(ret != -1) return ret;

	if(sum > 31) return ret = 1; //winning for opponent
	if(sum == 31) return ret = 0; //losing for opponent

	for(int i=1; i<=6; i++) {
		if(num[i] < 4) {
			num[i]++;
			if(solve(sum+i) == 0) { //if we can move to losing state
				num[i]--;
				return ret = 1;
			}
			num[i]--;
		}
	}
	return ret = 0;
}

int main() {
	string s;
	while(cin >> s) {
		int sum=0;
		memset(dp, -1, sizeof dp);
		memset(num, 0, sizeof num);
		for(char c : s) sum += c-'0', num[c-'0']++;


		cout << s << " ";
		if(solve(sum)) {
			if(s.length()%2 == 0) cout << "A\n";
			else cout << "B\n";
		} else {
			if(s.length()%2 == 0) cout << "B\n";
			else cout << "A\n";
		}
	}

	return 0;
}
