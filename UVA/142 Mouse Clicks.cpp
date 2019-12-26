#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

struct Icon {
	int x,y;
	bool vis=1;
	Icon(int x, int y) : x(x), y(y) {}
};

struct Reg {
	int x1,y1,x2,y2;
	Reg(int x1, int y1, int x2, int y2) :
		x1(x1), y1(y1), x2(x2), y2(y2) {}
};

double dist(int x1, int y1, int x2, int y2) {
	return hypot(x1-x2, y1-y2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char t,q=0;
	int x1,y1,x2,y2;
	vector<Icon> ic;
	vector<Reg> rg;

	while(cin >> t && t != '#') {
		cin >> x1 >> y1;
		if(t == 'R') {
			cin >> x2 >> y2;
			rg.push_back(Reg(x1,y1,x2,y2));
		} else if(t == 'I') {
			ic.push_back(Icon(x1,y1));
		} else {
			if(!q) {
				for(auto &i : ic)
					for(auto &r : rg)
						if(r.x1 <= i.x && i.x <= r.x2 && r.y1 <= i.y && i.y <= r.y2)
							{i.vis = 0; break;}
				q = 1;
			}

			int ans=-1;
			for(int i=sz(rg)-1; i>=0; i--)
				if(rg[i].x1 <= x1 && x1 <= rg[i].x2 && rg[i].y1 <= y1 && y1 <= rg[i].y2)
					{ans = i; break;}
			if(ans != -1) {printf("%c\n", 'A'+ans); continue;}

			double mn=INF;
			for(auto i : ic)
				if(i.vis)
					mn = min(mn, dist(x1,y1, i.x,i.y));
			for(int i=0; i<sz(ic); i++)
				if(ic[i].vis && fabs(mn-dist(x1,y1, ic[i].x,ic[i].y)) < EPS)
					printf("%3d", i+1);
			printf("\n");
		}
	}

	return 0;
}
















