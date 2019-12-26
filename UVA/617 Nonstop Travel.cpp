#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;


int main() {
	int n,t=1;
	while(cin >> n && n != -1) {
		double arr[n][5];
		for(int i=0; i<n; i++) {
			for(int j=0; j<4; j++)
				cin >> arr[i][j];
			arr[i][4] = arr[i][1]+arr[i][2]+arr[i][3];
		}

		bool pass;
		vector<int> v;
		for(int s=30; s<=60; s++) {
			double x = s/60.0/60.0;
			pass = true;
			for(int i=0; i<n; i++) {
				double arrive = arr[i][0]/x;
				double test = arrive - ((int)arrive/(int)arr[i][4])*arr[i][4];
				if(!(test <= arr[i][1]+arr[i][2] || test == arr[i][1]+arr[i][2]+arr[i][3])) pass=false;
			}
			if(pass) v.push_back(s);
		}

		cout << "Case " << t << ": ";
		for(int i=0; i<(int)v.size()-1; i++) {
			if(i!=0 && v[i+1]-v[i]==1 && v[i]-v[i-1]==1) continue;
			if(v[i+1]-v[i] == 1) cout << v[i] << "-";
			else cout << v[i] << ", ";
		}
		if(!v.empty())
			cout << v.back() << "\n";
		else
			cout << "No acceptable speeds.\n";
		t++;
	}





	return 0;
}
