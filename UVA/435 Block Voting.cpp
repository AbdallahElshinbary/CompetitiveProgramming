#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
	int t,p,h,cnt,power;
	int arr[25];
	cin >> t;
	while(t--) {
		cin >> p;
		h = 0;
		for(int i=0; i<p; i++) {
			cin >> arr[i];
			h+=arr[i];
		}
		h = (h/2)+1;
		for(int i=0; i<p; i++) {
			power = 0;
			for(int j=1; j<(1 << p); j++) {
				cnt = 0;
				if(j & (1 << i)) continue;
				for(int k=0; k<p; k++) {
					if(j & (1 << k))
						cnt += arr[k];
				}
				if(cnt >= h) continue;
				if(cnt+arr[i] >= h) power++;
			}
			printf("party %d has power index %d\n", i+1, power);
		}
		printf("\n");
	}


	return 0;
}
