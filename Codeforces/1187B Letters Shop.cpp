#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m,ans;
	string s;
	int first[26];
	vector<int> v[26];
	cin >> n >> s;
	for(int i=0; i<n; i++) v[s[i]-'a'].push_back(i);

	cin >> m;
	while(m--) {
		int freq[26]{};
		cin >> s; ans=-1;
		for(char c : s) ans = max(ans, v[c-'a'][freq[c-'a']]), freq[c-'a']++;
		cout << ans+1 << "\n";
	}


	return 0;
}

