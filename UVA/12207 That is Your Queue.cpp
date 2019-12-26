#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t=1, p, c, x;
	char h;
	while(cin >> p >> c && p) {
		deque<int> d;
		for(int i=1; i<=min(p, c); i++) d.push_back(i);

		cout << "Case " << t++ << ":\n";
		for(int i=0; i<c; i++) {
			cin >> h;
			if(h == 'E') {
				cin >> x;
				for(int i=0; i<(int)d.size(); i++) if(d[i] == x) d.erase(d.begin()+i);
				d.push_front(x);
			} else {
				x = d.front(); d.pop_front();
				cout << x << "\n";
				d.push_back(x);
			}
		}
	}

	return 0;
}



