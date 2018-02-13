#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	while(cin >> n && n != 0) {
		vector<vector<int> > v;
		for(int i=0; i<n ;i++) {
			vector<int> temp;
			for(int j=0; j<5; j++) {
				cin >> x;
				temp.push_back(x);
			}
			sort(temp.begin(), temp.end());
			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		int temp=1, m=1, cnt=1;

		for(int i=0 ;i<v.size()-1; i++) {
			if(v[i] == v[i+1])
				temp++;
			else {
				if(m == temp) {
					cnt += temp;
					m = temp;
				} else if(m < temp) {
					cnt = temp;
					m = temp;
				}
				temp = 1;
			}
		}
		if(m == temp && temp != 1)
			cnt += temp;
		else if(m < temp)
			cnt = temp;


		cout << cnt << "\n";
	}
}
