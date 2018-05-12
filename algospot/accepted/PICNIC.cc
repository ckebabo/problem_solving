#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void foo(vector<int> G[], int v[], int u, int N) {
	if(u>=N) {
		bool found = true;
		for(int i=0;i<N;i++) {
			if(v[i]==-1) { found=false; break; }
		}
		if(found) { ans+=1; }

		return;
	}

	if(v[u] != -1) {
		foo(G, v, u+1, N);
		return;
	}

	for(int i=0;i<G[u].size();i++) {
		int f = G[u][i];
		if(v[f] != -1) continue;

		v[u] = f; v[f] = u;
		foo(G, v, u+1, N);
		v[u] = -1; v[f] = -1;
	}
}

int main() {
	int C;
	cin >> C;
	while(C--) {
		int n,m;
		cin >> n >> m;

		vector<int> G[10];
		for(int i=0;i<m;i++) {
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		int v[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
		ans = 0;
		foo(G, v, 0, n);

		cout << ans << endl;
	}

	return 0;
}
