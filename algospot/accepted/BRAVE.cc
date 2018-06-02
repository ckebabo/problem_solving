#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(vector<int> G[], int N, int v[], int u, int c) {
	v[u] = c;
	for(auto n : G[u]) {
		if(v[n]==0) dfs(G, N, v, n, c);
	}
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N,M;
		cin >> N >> M;

		vector<int> G[100005];
		while(M--) {
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		int v[100005] {0,};
		int color=1;
		for(int i=1;i<=N;i++) {
			if(v[i]==0) {
				dfs(G, N, v, i, color);
				color+=1;
			}
		}

		int ans = 0;
		map<int,int> mm;
		for(int i=1;i<=N;i++) {
			mm[v[i]] += 1;
			ans = max(mm[v[i]], ans);
		}

		cout << ans << endl;
	}

	return 0;
}
