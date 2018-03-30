#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

	int t,n;
	double x1,y1,x2,y2,p;
	map<double, double> mp;
	vector<pair<pair<double, double>, double > > vec;
	vector<double> points;
	cin >> t;
	while(t--) {
		cin >> n;
		while(n--) {
			cin >> x1 >> y1 >> x2 >> y2 >> p;
			if(x1 > x2)
				swap(x1,x2);
			vec.push_back({{x1,x2}, p});
			points.push_back(x1), points.push_back(x2);

			mp[x1] = p;
			mp[x2] = 1;
		}
		sort(vec.begin(), vec.end());
		sort(points.begin(), points.end());

		for(int i=0; i<(int)vec.size(); i++) {
			for(int j=0; j<(int)vec.size(); j++) {
				if(i == j) continue;
				if(vec[i].first.first < vec[j].first.first && vec[i].first.second > vec[j].first.first)
					mp[vec[j].first.first] *= vec[i].second;
				if(vec[i].first.first < vec[j].first.second && vec[i].first.second > vec[j].first.second)
					mp[vec[j].first.second] *= vec[i].second;
			}
		}

		printf("%d\n-inf %.3f 1.000\n", points.size()+1, points[0]);

		for(int i=0; i<(int)points.size()-1; i++)
			printf("%.3f %.3f %.3f\n", points[i], points[i+1], mp[points[i]]);

		printf("%.3f +inf 1.000\n", points[points.size()-1]);

		if(t) printf("\n");

		mp.clear(); vec.clear(); points.clear();
	}


    return 0;
}

