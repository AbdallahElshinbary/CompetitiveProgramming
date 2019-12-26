#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	bool rooms[10]{};
	cin >> n >> s;
	for(char c : s) {
		if(isdigit(c))
			rooms[c-'0'] = 0;
		else {
			if(c == 'L') {
				for(int i=0; i<10; i++) if(!rooms[i]) {rooms[i]=1; break;}
			}
			else {
				for(int i=9; i>=0; i--) if(!rooms[i]) {rooms[i]=1; break;}
			}
		}
	}

	for(int i=0; i<10; i++) cout << rooms[i];

}




















