#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,a,b;
	while(cin >> n && n!=0) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;

		bool ss=true, qq=true, pqq=true;
		while(n--) {
			cin >> a >> b;
			if(a == 1) {
				s.push(b); q.push(b); pq.push(b);
			} else {
				if(s.size() == 0)
					ss = qq  = pqq = false;
				else {
					if(s.top() != b) ss=false;
					if(q.front() != b) qq=false;
					if(pq.top() != b) pqq=false;
					s.pop(); q.pop(); pq.pop();
				}
			}
		}

		if(ss+qq+pqq > 1)
			cout << "not sure\n";
		else if(ss+qq+pqq == 0)
			cout << "impossible\n";
		else if(ss)
			cout << "stack\n";
		else if(qq)
			cout << "queue\n";
		else
			cout << "priority queue\n";
	}
	return 0;
}
