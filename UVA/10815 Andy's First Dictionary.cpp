#include <bits/stdc++.h>
using namespace std;

int main() {

	string s,temp;
	set<string> ss;

	while(cin >> s) {
		for(int i=0 ;i<s.length(); i++) {
			if(isalpha(s[i]))
				temp += tolower(s[i]);
			else {
				if(temp != "") {
					ss.insert(temp);
					temp = "";
				}
			}
		}

		if(temp != "") {
			ss.insert(temp);
			temp = "";
		}
	}


	for(string c : ss)
		cout << c << "\n";

	return 0;
}
