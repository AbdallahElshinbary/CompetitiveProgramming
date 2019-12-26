#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int valid(int i, int j) {
	return (i >= 0 && i < 3 && j >= 0 && j < 3);
}

int dx[] = {0,0,0,1,-1};
int dy[] = {0,1,-1,0,0};

map<char, pair<int, int> > mp = {
		{'a', {0, 0}}, {'b', {0, 1}}, {'c', {0, 2}},
		{'d', {1, 0}}, {'e', {1, 1}}, {'f', {1, 2}},
		{'g', {2, 0}}, {'h', {2, 1}}, {'i', {2, 2}},
};

int main() {
	string s;
	int t=1,x,y;
	int arr[3][3];
	while(getline(cin, s)) {
		memset(arr, 0, sizeof arr);
		for(char c : s) {
			x = mp[c].first, y = mp[c].second;
			for(int i=0; i<5; i++)
				if(valid(x+dx[i], y+dy[i])) arr[x+dx[i]][y+dy[i]] = (arr[x+dx[i]][y+dy[i]]+1)%10;
		}
		printf("Case #%d:\n", t++);
		printf("%d %d %d\n", arr[0][0], arr[0][1], arr[0][2]);
		printf("%d %d %d\n", arr[1][0], arr[1][1], arr[1][2]);
		printf("%d %d %d\n", arr[2][0], arr[2][1], arr[2][2]);
	}

	return 0;
}
