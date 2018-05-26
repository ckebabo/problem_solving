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
			int s = 0, pp = 0;
			sort(begin(p[i]), end(p[i]));
			for(int j=1;j<N;j++) {
				s += p[i][j].second;
				pp += p[i][j].first;
			}
			ans = min(ans, s+p[i][0].second-pp);
		}

		cout << ans << endl;
	}

	return 0;
}
