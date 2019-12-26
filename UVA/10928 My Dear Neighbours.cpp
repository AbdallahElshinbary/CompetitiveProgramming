#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,x,mn;
	string s;
	vector<int> indices;
	cin >> t;
	while(t--) {
		cin >> n;
		cin.ignore();
		mn = INT_MAX;
		for(int i=1; i<=n; i++) {
			getline(cin, s);
			x = 1;
			for(char c : s)
				if(c == ' ')
					x++;
			if(x < mn)
				mn = x, indices.clear(), indices.push_back(i);
			else if(x == mn)
				indices.push_back(i);
		}
		cout << indices[0];
		for(int i=1; i<indices.size(); i++)
			cout << " " << indices[i];
		cout << "\n";
		indices.clear();
	}

	return 0;
}

