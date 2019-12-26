#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define mp make_pair
#define INF 1e9

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll ans=0;
	string s;
	cin >> s;

	ll freq[130]{};
	for(char c : s) freq[(int)c]++;
	for(int i=0; i<130; i++) ans += (freq[i]*freq[i]);
	cout << ans;

	return 0;
}

















