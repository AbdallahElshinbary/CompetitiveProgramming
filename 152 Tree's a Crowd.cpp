#include <bits/stdc++.h>

using namespace std;

int main()
{
	double x,y,z,d;
	pair<pair<double, double>, double > arr[5005];
	int dist[5005],freq[10]{};
	int n = 0;
	fill(dist, dist+5005, 1e9);

	while(cin >> x >> y >> z && (x || y || z)) {
		arr[n].first = {x,y}, arr[n].second = z;
		n++;
	}

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			d = sqrt((arr[i].first.first-arr[j].first.first)*(arr[i].first.first-arr[j].first.first) +
			    (arr[i].first.second-arr[j].first.second)*(arr[i].first.second-arr[j].first.second) +
			    (arr[i].second-arr[j].second)*(arr[i].second-arr[j].second));

			dist[i] = min(dist[i], (int)d);
			dist[j] = min(dist[j], (int)d);
		}
	}

	for(int i=0; i<n; i++)
		if(dist[i] < 10)
			freq[dist[i]]++;

	for(int i=0; i<=9; i++)
		cout << " " << setw(3) << freq[i];
	cout << endl;


    return 0;
}

