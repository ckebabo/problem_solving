#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		int N, M;
		cin >> N >> M;

		vector<pair<int,int>> p[100];
		for(int i=0;i<N;i++) {
			pair<int,int> pp;
			for(int j=0;j<M;j++) {
				cin >> pp.second >> pp.first;
				p[j].push_back(pp);
			}
		}

		int ans = 2000000;
		for(int i=0;i<M;i++) {
			int now=0, pp=0;
			sort(begin(p[i]), end(p[i]), greater<pair<int,int>>());
			for(int j=0;j<N;j++) {
				const int cost = max(p[i][j].second - pp, 0);
				now += cost;
				pp = pp - p[i][j].second + cost + p[i][j].first;
			}
			ans = min(ans, now);
		}

		cout << ans << endl;
	}

	return 0;
}
