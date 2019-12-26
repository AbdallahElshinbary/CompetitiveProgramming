#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
	int n;
	string a2[] = {"00", "01", "81"};
	string a4[] = {"0000", "0001", "2025", "3025", "9801"};
	string a6[] = {"000000", "000001", "088209", "494209", "998001"};
	string a8[] = {"00000000", "00000001", "04941729", "07441984", "24502500", "25502500", "52881984", "60481729", "99980001"};
	while(cin >> n && n) {
		if(n == 2) for(int i=0; i<int(sizeof(a2)/sizeof(a2[0])); i++) cout << a2[i] << "\n";
		if(n == 4) for(int i=0; i<int(sizeof(a4)/sizeof(a4[0])); i++) cout << a4[i] << "\n";
		if(n == 6) for(int i=0; i<int(sizeof(a6)/sizeof(a6[0])); i++) cout << a6[i] << "\n";
		if(n == 8) for(int i=0; i<int(sizeof(a8)/sizeof(a8[0])); i++) cout << a8[i] << "\n";
	}

	return 0;
}
