#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int arr[12];
int state[1000005];

int main() {
	while(cin >> n >> m) {
		memset(state, false, sizeof state);

		for(int i=0; i<m; i++) {
			cin >> arr[i];
			state[arr[i]]=true;
		}

		state[0] = 0;
		for(int i=1; i<=n; i++) {
			if(state[i]) continue;
			state[i] = false;
			for(int j=0; j<m; j++) {
				if(arr[j] <= i)
					if(state[i-arr[j]] == false) {state[i] = true; break;}
			}
		}

		cout << (state[n] ? "Stan wins\n" : "Ollie wins\n");
	}

	return 0;
}
