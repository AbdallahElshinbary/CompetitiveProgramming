#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Packet {
	int message;
	int start;
	int end;
};

int main() {
	int n, m, curr, buffer_size, semi_buffer, ans_buffer, TC=1;
	int sizes[6], idx[6];
	Packet packets[1005];
	vector<Packet> buffer;

	while(cin >> n >> m && n) {
		ans_buffer = 1e9;

		for(int i=1; i<=n; i++) cin >> sizes[i];
		for(int i=0; i<m; i++) cin >> packets[i].message >> packets[i].start >> packets[i].end;

		int arr[] = {1,2,3,4,5};
		do {
			curr = buffer_size = semi_buffer = 0;
			for(int i=1; i<=n; i++) idx[i]=1;

			for(int i=0; i<m; i++) {
				if(packets[i].message == arr[curr] && packets[i].start == idx[arr[curr]]) {
					if(packets[i].end == sizes[arr[curr]]) curr++;
					else idx[arr[curr]] = packets[i].end+1;

					//Clean the buffer
					bool x;
					while(true) {
						x = false;
						for(Packet packet : buffer) {
							if(packet.message == arr[curr] && packet.start == idx[arr[curr]]) {
								if(packet.end == sizes[arr[curr]]) curr++;
								else idx[arr[curr]] = packet.end+1;
								x = true;
								buffer_size -= packet.end-packet.start+1;
							}
						}
						if(!x) break;
					}

				} else {
					buffer.push_back(packets[i]);
					buffer_size += packets[i].end-packets[i].start+1;
					semi_buffer = max(semi_buffer, buffer_size);
				}
			}

			ans_buffer = min(ans_buffer, semi_buffer);
			buffer.clear();

		} while(next_permutation(arr, arr+n));

		printf("Case %d: %d\n\n", TC++, ans_buffer);
	}

	return 0;
}
