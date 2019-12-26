#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define mp make_pair
#define INF 1e9

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a,b;
	getline(cin, a);
	getline(cin, b);

	int freq[130]{};
	for(char c : a) freq[(int)c]++;
	for(char c : b) {
		if(!isspace(c) && !freq[(int)c]) {cout << "NO"; return 0;}
		freq[(int)c]--;
	}
	cout << "YES";

	return 0;
}

















