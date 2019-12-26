#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s;
	int cap[100005];
	while(getline(cin, s)) {
		vector<int> v;
		stringstream ss(s);
		string num;
		while(getline(ss, num, ' '))
			v.push_back(stoi(num));

		stack<pair<int, int> > st;
		bool ok = true;
		int x;
		for(int i=0; i<(int)v.size(); i++) {
			x = v[i];
			if(x > 0) {
				if(st.empty()) {
					ok = false; break;
				} else if(x != -st.top().second) {
					ok = false; break;
				} else {
					st.pop();
					if(st.empty()) continue;
					cap[st.top().first] -= x;
					if(cap[st.top().first] <= 0) {
						ok = false; break;
					}
				}
			} else {
				if(!st.empty() && -x > -st.top().second) {
					ok = false; break;
				}
				st.push(make_pair(i, x));
				cap[i] = -x;
			}
		}
		if(st.size() != 0) ok = false;
		cout << ((ok) ? ":-) Matrioshka!\n" : ":-( Try again.\n");
	}

	return 0;
}
