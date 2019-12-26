#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, double> ii;

#define INF 1e9
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int arr[200005];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];

	int p = max_element(arr, arr+n) - arr;
	if(is_sorted(arr, arr+p) && is_sorted(arr+p, arr+n, greater<int>()))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
















