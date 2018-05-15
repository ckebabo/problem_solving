#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		int N, M;
		cin >> N >> M;

		vector<pair<int, double>> G[10001];
		for(int i=0;i<M;i++) {
			int u,v;
			double w;
			cin >> u >> v >> w;
			G[u].push_back({v,w});
			G[v].push_back({u,w});
		}

		double dist[10001] = {0,};
		for(int i=1; i<N; i++) dist[i] = -1;
		multimap<double,int> mm;
		mm.insert({1,0});
		while(!mm.empty()) {
			double w = mm.begin()->first;
			int u = mm.begin()->second;

			mm.erase(mm.begin());

			for(int i=0;i<G[u].size();i++) {
				int v = G[u][i].first;
				double neww = w * G[u][i].second;
				if(dist[v] < 0 || dist[v] > neww) {
					dist[v] = neww;
					mm.insert({dist[v], v});
				}
			}
		}

		printf("%.10lf\n", dist[N-1]);
	}

	return 0;
}
