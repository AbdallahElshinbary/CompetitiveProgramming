#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	while(cin >> s) {
		string res = "", temp = "";
		bool home = false;
		for(char c : s) {
			if(c == '[') {
				home = true;
				res = temp + res;
				temp = "";
				continue;
			} else if(c == ']') {
				home = false;
				continue;
			}
			if(home)
				temp += c;
			else
				res += c;
		}
		if(temp != "")
			res = temp + res;
		cout << res << "\n";
	}
}



