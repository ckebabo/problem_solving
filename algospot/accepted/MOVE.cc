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

		vector<pair<int, int>> G[10001];
		for(int i=0;i<M;i++) {
			int u,v;
			int w;
			cin >> u >> v >> w;
			G[u].push_back({v,w});
			G[v].push_back({u,w});
		}

		int dist[10001] = {0,};
		for(int i=1; i<N; i++) dist[i] = -1;
		multimap<int,int> mm;
		mm.insert({0,0});
		while(!mm.empty()) {
			int w = mm.begin()->first;
			int u = mm.begin()->second;

			mm.erase(mm.begin());

			for(int i=0;i<G[u].size();i++) {
				int v = G[u][i].first;
				int neww = w + G[u][i].second;
				if(dist[v] < 0 || dist[v] > neww) {
					dist[v] = neww;
					mm.insert({dist[v], v});
				}
			}
		}

		cout << dist[N-1] << endl;
	}

	return 0;
}
