#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int LIMIT = 10005;
int t,x,y;
bool prime[LIMIT];
vector<int> primes;
vector<vector<int> > adj(10005);
int dist[10005];

void sieve() {
	for(int i=0; i<LIMIT; i++) prime[i]=true;
	prime[0]=prime[1]=false;

	for(int i=2; i*i<=LIMIT; i++)
		if(prime[i])
			for(int j=i*2; j<LIMIT; j+=i) prime[j]=false;

	for(int i=1000; i<=9999; i++)
		if(prime[i]) primes.push_back(i);
}

bool valid(string a, string b) {
	int cnt=0;
	for(int i=0; i<4; i++) {
		if(a[i] != b[i]) cnt++;
		if(cnt == 2) return false;
	}
	return true;
}

int bfs(int s, int d) {
	queue<int> q;
	q.push(s);

	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int x : adj[u]) {
			if(dist[x] == 0) {
				q.push(x);
				dist[x] = dist[u]+1;
			}
		}
	}

	return dist[d];
}

int main() {
	sieve();
	sort(primes.begin(), primes.end());

	for(int i=0; i<(int)primes.size(); i++) {
		for(int j=i+1; j<(int)primes.size(); j++) {
			if(valid(to_string(primes[i]), to_string(primes[j]))) {
				adj[primes[i]].push_back(primes[j]);
				adj[primes[j]].push_back(primes[i]);
			}
		}
	}

	cin >> t;
	while(t--) {
		cin >> x >> y;
		if(x == y) {
			cout << "0\n";
			continue;
		}
		memset(dist, 0, sizeof dist);
		cout << bfs(x, y) << "\n";
	}
	return 0;
}
