#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool vowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
	int n, cnt;
	string x, words[100005];
	pair<pair<int, char>, int> arr[100005];
	pair<pair<int, char>, int> arr2[100005];

	cin >> n;
	for(int i=0; i<n; i++) cin >> words[i];

	for(int i=0; i<n; i++) {
		arr[i].second = i;
		x = words[i];
		for(int j=x.length()-1; j>=0; j--)
			if(vowel(x[j])) {arr[i].first.second = x[j]; break;}

		cnt = 0;
		for(char c : x) if(vowel(c)) cnt++;
		arr[i].first.first = cnt;
	}

	sort(arr, arr+n);

	vector<pair<int, int> > v1, v2;

	bool take[100005]{};

	int tk = 0;

	for(int i=0; i<n-1; ) {
		if(arr[i].first.first == arr[i+1].first.first && arr[i].first.second == arr[i+1].first.second) {
				v2.push_back(make_pair(arr[i].second, arr[i+1].second));
				take[i] = take[i+1]=1; i += 2, tk += 2;
		} else i++;
	}

	int s = 0;
	for(int i=0; i<n; i++)
		if(!take[i])
			arr2[s++] = arr[i];

	for(int i=0; i<s-1;) {
		if(arr2[i].first.first == arr2[i+1].first.first) {
			v1.push_back(make_pair(arr2[i].second, arr2[i+1].second)); i+= 2;
		} else i++;
	}

	int i=0, j=0, s1 = (int)v1.size(), s2 = (int)v2.size();

	if(s2 > s1) {
		cout << s1 + (s2-s1)/2 << "\n";
	} else {
		cout << s2 << "\n";
	}

	while(1) {
		if(j == s2) break;
		if(i < s1) {
			cout << words[v1[i].first] << " " << words[v2[j].first] << "\n";
			cout << words[v1[i].second] << " " << words[v2[j].second] << "\n";
			i++, j++;
		} else if(s2-j >= 2) {
			cout << words[v2[j].first] << " " << words[v2[j+1].first] << "\n";
			cout << words[v2[j].second] << " " << words[v2[j+1].second] << "\n";
			j += 2;
		} else break;
	}

	return 0;
}
















