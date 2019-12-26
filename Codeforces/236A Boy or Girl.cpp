//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//	vector<string> possible =  {"1-100","100-200","200-300"}
//					 , hints 	=  {"50-75","250-1000"};
//
//		map<int, int> freq;
//		int p, x;
//		for(auto s : possible) {
//			stringstream ss(s);
//			p=-1;
//			while(ss >> x) {
//				if(p == -1 || x > 0) freq[x]++;
//				else if(x < 0) {
//					x = abs(x);
//					freq[x]++;
//					for(auto f : freq)
//						if(f.first > p && f.first < x) freq[f.first]++;
//				}
//				p = x;
//			}
//		}
//
//		int mx, item;
//		for(auto s : hints) {
//			mx = -1;
//			for(auto f : freq)
//				if(f.second > mx) mx = f.second, item = f.first;
//			cout << item << "\n";
//
//			stringstream ss(s);
//			p=-1;
//			while(ss >> x) {
//				if(p == -1 || x > 0) {
//					for(auto f : freq)
//					freq[x]--;
//				}
//				else if(x < 0) {
//					x = abs(x);
//					freq[x]--;
//					for(auto f : freq)
//						if(f.first > p && f.first < x) freq[f.first]--;
//				}
//				p = x;
//			}
//		}
//
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s;
	set<char> ss;
	cin >> s;
	for(char c : s) ss.insert(c);
	cout << (ss.size()%2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");

	return 0;
}
