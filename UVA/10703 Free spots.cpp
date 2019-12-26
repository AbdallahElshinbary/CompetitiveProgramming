#include <bits/stdc++.h>
using namespace std;

int main() {
	int w,h,n,x1,x2,y1,y2;
	while(cin >> w >> h >> n && w != 0) {
		bool arr[h][w]{};
		for(int i=0; i<n; i++) {
			cin >> x1 >> y1 >> x2 >> y2;
			for(int i=min(y1,y2)-1; i<max(y1,y2); i++)
				for(int j=min(x1,x2)-1; j<max(x1,x2); j++)
					arr[i][j] = true;
		}

		int cnt = 0;
		for(int i=0 ;i<h; i++)
			for(int j=0; j<w; j++)
				if(!arr[i][j]) cnt++;

		if(cnt == 0)
			cout << "There is no empty spots.\n";
		else if(cnt == 1)
			cout << "There is one empty spot.\n";
		else
			cout << "There are " << cnt << " empty spots.\n";
	}
	return 0;
}
