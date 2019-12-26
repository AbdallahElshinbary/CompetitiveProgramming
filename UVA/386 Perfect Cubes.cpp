#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cub(int x) {
	return x*x*x;
}

int main() {
	vector<pair<pair<int, int>, pair<int,int> > > v;

	for(int a=2; a<=200; a++) {
		for(int b=2; b<200; b++) {
			for(int c=2; c<=200; c++) {
				int dd = cub(a)-cub(b)-cub(c);
				int d = cbrt(dd);

				if(d*d*d != dd) d++;
				if(d*d*d == dd && d > 1) {
					int arr[] = {b,c,d};
					sort(arr, arr+3);
					auto x = make_pair(make_pair(a, arr[0]),make_pair(arr[1],arr[2]));
					if(find(v.begin(), v.end(), x) == v.end()) {
						cout << "Cube = " << a << ", Triple = (" << arr[0] << "," << arr[1] << "," << arr[2] << ")\n";
						v.push_back(x);
					}
				}
			}
		}
	}

	return 0;
}
