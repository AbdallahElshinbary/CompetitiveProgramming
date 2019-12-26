#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	string s;
	cin >> n >> s;

	int freq[2]{};
	for(char c : s) freq[c-'0']++;
	if(freq[0] == freq[1]) {
		cout << "2\n";
		char c = s.back(); s.pop_back();
		cout << s << " " << c;
	} else {
		cout << "1\n" << s;
	}



	return 0;
}

