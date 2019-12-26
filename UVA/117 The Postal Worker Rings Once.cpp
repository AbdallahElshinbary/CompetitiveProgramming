#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define ii make_pair
#define INF 1e9

int AdjMat[30][30];
int deg[30];

int main() {
	int a,b,w,ans;
	string s;

	while(cin >> s) {
		ans=0;
		memset(deg, 0, sizeof deg);

		do {
			w = (int)s.size();
			a = s[0]-'a', b = s.back()-'a';
			deg[a]++, deg[b]++; ans += w;
			AdjMat[a][b] = AdjMat[b][a] = w;
		}
		while(cin >> s && s != "deadend");

		a = b = -1;
		for(int i=0; i<26; i++) {
			if(deg[i] & 1) {
				if(a == -1) a = i;
				else b = i;
			}
		}

		if(a != -1) {
			for(int i=0; i<26; i++)
				for(int j=0; j<26; j++)
					if(!AdjMat[i][j])
						AdjMat[i][j] = AdjMat[j][i] = INF;

			for(int k=0; k<26; k++)
				for(int i=0; i<26; i++)
					for(int j=0; j<26; j++)
						AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
			ans += AdjMat[a][b];
		}

		cout << ans << "\n";
	}

	return 0;
}
