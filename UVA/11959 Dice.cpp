#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
	int t,a,b;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		int ra[6], rb[6];
		for(int i=5; i>=0; i--)
			ra[i]=a%10, a/=10;
		for(int i=5; i>=0; i--)
			rb[i]=b%10, b/=10;

		//Spinning
		int arr[6][4][6] = {
			{{ra[0],ra[1],ra[2],ra[3],ra[4],ra[5]}, {ra[0],ra[1],ra[3],ra[4],ra[5],ra[2]}, {ra[0],ra[1],ra[4],ra[5],ra[2],ra[3]}, {ra[0],ra[1],ra[5],ra[2],ra[3],ra[4]}},
			{{ra[1],ra[0],ra[4],ra[3],ra[2],ra[5]}, {ra[1],ra[0],ra[3],ra[2],ra[5],ra[4]}, {ra[1],ra[0],ra[2],ra[5],ra[4],ra[3]}, {ra[1],ra[0],ra[5],ra[4],ra[3],ra[2]}},
			{{ra[2],ra[4],ra[1],ra[3],ra[0],ra[5]}, {ra[2],ra[4],ra[3],ra[0],ra[5],ra[1]}, {ra[2],ra[4],ra[0],ra[5],ra[1],ra[3]}, {ra[2],ra[4],ra[5],ra[1],ra[3],ra[0]}},
			{{ra[4],ra[2],ra[0],ra[3],ra[1],ra[5]}, {ra[4],ra[2],ra[3],ra[1],ra[5],ra[0]}, {ra[4],ra[2],ra[1],ra[5],ra[0],ra[3]}, {ra[4],ra[2],ra[5],ra[0],ra[3],ra[1]}},
			{{ra[5],ra[3],ra[2],ra[0],ra[4],ra[1]}, {ra[5],ra[3],ra[0],ra[4],ra[1],ra[2]}, {ra[5],ra[3],ra[4],ra[1],ra[2],ra[0]}, {ra[5],ra[3],ra[1],ra[2],ra[0],ra[4]}},
			{{ra[3],ra[5],ra[2],ra[1],ra[4],ra[0]}, {ra[3],ra[5],ra[1],ra[4],ra[0],ra[2]}, {ra[3],ra[5],ra[4],ra[0],ra[2],ra[1]}, {ra[3],ra[5],ra[0],ra[2],ra[1],ra[4]}},
		};

		bool ok;
		for(int i=0; i<6; i++) {
			for(int j=0; j<4; j++) {
				ok = true;
				for(int k=0; k<6; k++) {
					if(arr[i][j][k] != rb[k]) {
						ok = false;
						break;
					}
				}
				if(ok) break;
			}
			if(ok) break;
		}

		cout << (ok ? "Equal\n" : "Not Equal\n");
	}

	return 0;
}
