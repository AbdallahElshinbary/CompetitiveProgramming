#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string a,b;
	while(getline(cin, a) && getline(cin, b)) {
		stringstream ssa(a), ssb(b);
		int x;
		set<int> sa, sb;
		while(ssa >> x) sa.insert(x);
		while(ssb >> x) sb.insert(x);

		if(sa == sb) {cout << "A equals B\n"; continue;}

		map<int, int> mp;
		for(int x : sa) mp[x]++;
		for(int x : sb) mp[x]++;

		int f = 0;
		if(sa.size() < sb.size()) {
			for(int x : sa) f += mp[x];
			if(f == 2*(int)sa.size()) {cout << "A is a proper subset of B\n"; continue;}
		} else if(sa.size() > sb.size()) {
			for(int x : sb) f += mp[x];
			if(f == 2*(int)sb.size()) {cout << "B is a proper subset of A\n"; continue;}
		}
		f = 0;
		for(int x : sa) f += mp[x];
		for(int x : sb) f += mp[x];
		if(f == (int)sa.size() + (int)sb.size()) cout << "A and B are disjoint\n";
		else cout << "I'm confused!\n";
	}

	return 0;
}
