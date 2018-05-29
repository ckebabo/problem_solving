#include <iostream>
#include <vector>
#include <utility>
#include <deque>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int J;
		cin >> J;
		J=J*J;

		pair<int,int> start, end;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;

		int N;
		cin >> N;
		vector<pair<int,int>> pts(N);
		for(auto &p : pts) cin >> p.first >> p.second;
		pts.push_back(start);
		pts.push_back(end);

		int v[105] = {0,};
		v[N] = 1;
		deque<int> q;
		q.push_back(N);

		bool found = false;
		while(!q.empty()) {
			int t = q.front(); q.pop_front();
			if(t == N+1) {
				found = true;
				break;
			}

			for(int i=0;i<N+2;i++) {
				if(v[i] == 1) continue;

				int dist = (pts[t].first-pts[i].first)*(pts[t].first-pts[i].first) + (pts[t].second-pts[i].second)*(pts[t].second-pts[i].second);
				if(dist <= J) {
					v[i] = 1;
					q.push_back(i);
				}
			}
		}

		cout << (found ? "YES" : "NO" ) << endl;
	}

	return 0;
}
