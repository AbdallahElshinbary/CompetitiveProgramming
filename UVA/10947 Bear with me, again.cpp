#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int n;
double K,M;
double x[105], y[105], r[105];
double dist[105][105];

bool conn(int i, int j) {
	double d = hypot(x[i]-x[j], y[i]-y[j]) - r[i] - r[j];
	return (K*M >= d ? 1 : 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> K >> M) {
		cin >> x[0] >> y[0] >> r[0];
		cin >> x[1] >> y[1] >> r[1];
		cin >> n; n += 2;
		for(int i=2; i<n; i++)
			cin >> x[i] >> y[i] >> r[i];

		memset(dist, 0, sizeof dist);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dist[i][j] = conn(i, j);

		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					if(dist[i][k] && dist[j][k])
						dist[i][j] = 1;

		cout << (dist[0][1] ? "Larry and Ryan will escape!\n" : "Larry and Ryan will be eaten to death.\n");
	}

	return 0;
}
















