#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

struct Point {
	int x,y;
	Point() : x(0), y(0) {};
	Point(int x, int y) : x(x), y(y) {}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t=1,n,x,y;
	char z;
	map<char, Point> mp;

	while(cin >> n && n) {
		while(n--) {
			cin >> z >> x >> y;
			mp[z] = Point(x,y);
		}

		string ans;
		Point a,b,c,d;
		vector<string> v;

		for(auto i : mp) {
			ans += i.first, a = i.second;
			for(auto j : mp) {
				b = j.second;
				if(a.x < b.x && a.y == b.y) {
					ans += j.first;
					for(auto k : mp) {
						c = k.second;
						if(c.x == b.x && c.y < b.y) {
							ans += k.first;
							for(auto l : mp) {
								d = l.second;
								if(d.y == c.y && d.x == a.x)
									v.push_back((ans+l.first));
							}
							ans.pop_back();
						}
					}
					ans.pop_back();
				}
			}
			ans.pop_back();
		}

		sort(v.begin(), v.end());
		printf("Point set %d:", t++);
		if(v.empty()) printf(" No rectangles\n");
		else {
			int i;
			for(i=0; i<sz(v); i++) {
				if(!(i%10)) printf("\n");
				printf(" %s", v[i].c_str());
			}
			printf("\n");
		}
		mp.clear();
	}

	return 0;
}
















