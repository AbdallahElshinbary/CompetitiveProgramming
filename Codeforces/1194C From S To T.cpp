#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	int freq[3][30];
	string s,t,p;
	cin >> q;
	while(q--) {
		cin >> s >> t >> p;
		memset(freq, 0, sizeof freq);

		for(char c : s) freq[0][c-'a']++;
		for(char c : t) freq[1][c-'a']++;
		for(char c : p) freq[2][c-'a']++;

		bool ok=1;
		for(char c : t)
			if(freq[1][c-'a'] > freq[0][c-'a'] + freq[2][c-'a']) {ok=0; break;}
		if(!ok) {cout << "NO\n"; continue;}

		int i,j;
		for(i=0,j=0; i<sz(s) && j<sz(t);) {
			if(s[i] == t[j]) i++,j++;
			else j++;
		}
		if(i < sz(s)) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}

















