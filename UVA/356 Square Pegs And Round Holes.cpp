#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//(x-a)^2 + (y-b)^2 = r^2
	int t=0,n,a=150,b=150,r4,cnt,con,ins;
	while(cin >> n) {
		r4 = (2*n - 1) * (2*n - 1), con = ins = 0;
		for(int i=0; i<=305; i++) {
			for(int j=0; j<=305; j++) {
				cnt = 0;
				for(int x=i; x<=i+1; x++)
					for(int y=j; y<=j+1; y++)
						if(((x-a)*(x-a) + (y-b)*(y-b)) * 4 < r4) cnt++;
				if(cnt > 0) con++;
				if(cnt == 4) ins++;
			}
		}
		if(t++) printf("\n");
		printf("In the case n = %d, %d cells contain segments of the circle.\n", n, con-ins);
		printf("There are %d cells completely contained in the circle.\n", ins);
	}

	return 0;
}
















