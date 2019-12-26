#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e12
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

const int MOD = 998244353;

long long power(long long n, long long p) {
    long long cur = n, res = 1;
    while(p) {
        if(p&1){
            res *= cur;
             res %= MOD;
        }
        p /= 2;
        cur *= cur;
        cur %= MOD;
    }
    return res%MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll w,h;
	cin >> w >> h;
	cout << (4*power(2, h-1)*power(2, w-1))%MOD;

	return 0;
}




















