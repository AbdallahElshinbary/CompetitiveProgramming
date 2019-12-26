#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 105;
const int INF = 1e9;

int n,m;
double a[MAXN][MAXN];
int link[MAXN], par[MAXN], used[MAXN];
double u[MAXN], v[MAXN], minval[MAXN];

int main() {
    while(scanf("%d %d", &n, &m) && n) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%lf", &a[i][j]);

		memset(used, 0, sizeof used);
		memset(u, 0, sizeof u);
		memset(v, 0, sizeof v);
		memset(par, 0, sizeof par);
		memset(link, 0, sizeof link);
		memset(minval, 0, sizeof minval);

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < MAXN; j++) {
				used[j] = false;
				minval[j] = INF;
			}
			int j_cur = 0;
			par[j_cur] = i;
			do {
				used[j_cur] = true;
				int j_next, i_cur = par[j_cur];
				double delta = INF;
				for (int j = 0; j <= m; j++)
					if (!used[j]) {
						double cur = a[i_cur][j] - u[i_cur] - v[j];
						if (cur < minval[j]) {
							minval[j] = cur; link[j] = j_cur;
						}
						if (minval[j] < delta) {
							delta = minval[j]; j_next = j;
						}
					}
				for (int j = 0; j <= m; j++)
					if (used[j]) {
						u[par[j]] += delta; v[j] -= delta;
					}
					else {
						minval[j] -= delta;
					}
				j_cur = j_next;
			} while (par[j_cur]);
			do {
				int j_prev = link[j_cur];
				par[j_cur] = par[j_prev];
				j_cur = j_prev;
			} while (j_cur > 0);
		}

		printf("%.2lf\n", -v[0]/n + 0.000000001);
    }
    return 0;
}
