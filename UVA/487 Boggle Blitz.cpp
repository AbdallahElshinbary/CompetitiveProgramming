#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int idx[] = {0,0,1,1,1,-1,-1,-1};
int idy[] = {1,-1,0,1,-1,0,1,-1};

int n,x,y;
char arr[22][22];
bool vis[22][22];
vector<string> vv;
set<string> ss;

bool cmp(string &a, string &b) {
	if(a.size() == b.size())
		return a<b;
	return a.size()<b.size();
}

void rec(int i, int j, string s) {
	s.push_back(arr[i][j]);
	vis[i][j]=true;
	if(s.size() >= 3 && s.size() <= n*n) {
		ss.insert(s);
	}

	for(int a=0; a<8; a++) {
		x = i+idx[a], y = j+idy[a];
		if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && arr[i][j] < arr[x][y])
			rec(x, y, s);
	}
	vis[i][j]=false;
	s.pop_back();
}


int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin >> arr[i][j];
		string s;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				rec(i,j,"");

		vv.assign(ss.begin(), ss.end());
		ss.clear();
		sort(vv.begin(), vv.end(), cmp);
		for(string s : vv) cout << s << "\n";

		if(t) cout << "\n";
	}

	return 0;
}
