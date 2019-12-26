#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-6
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,a=0,b=0;
	string s;
	cin >> n >> s;
	for(char c : s) a += (c == 'n');
	for(char c : s) b += (c == 'z');
	while(a--) cout << "1 ";
	while(b--) cout << "0 ";


	return 0;
}




















