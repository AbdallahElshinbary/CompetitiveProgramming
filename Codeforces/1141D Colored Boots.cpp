#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, cnt=0, off=0;
	bool taken[150005]{};
	vector<int> v[130];
	vector<int> q;
	vector<pair<int, int> > ans;
	string l,r;
	cin >> n >> l >> r;
	for(int i=0; i<n; i++)  v[r[i]].push_back(i);

	for(int i=0; i<n; i++) {
		if(l[i] == '?') {cnt++, off++; q.push_back(i); continue;}

		if(v[l[i]].size() > 0) {
			ans.push_back(make_pair(i+1, v[l[i]].back()+1));
			taken[v[l[i]].back()]=1;
			v[l[i]].pop_back();
			cnt++;
		}
		else if(v['?'].size() > 0) {
			ans.push_back(make_pair(i+1, v['?'].back()+1));
			taken[v['?'].back()]=1;
			v['?'].pop_back();
			cnt++;
		}
	}

	for(int i=0; i<n; i++)
		if(!taken[i] && q.size() > 0) {ans.push_back(make_pair(q.back()+1, i+1)); q.pop_back();}

	cout << cnt << "\n";
	for(auto x : ans) cout << x.first << " " << x.second << "\n";


	return 0;
}
