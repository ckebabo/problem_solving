#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

int solve(vector<int> G[], int N, int a, int b)
{
	int p[100] = {0,};
	p[a-1] = p[b-1] = 1;

	deque<int> q;
	q.push_back(a-1);
	q.push_back(b-1);

	map<int, set<int> > mm;

	int t;
	while(!q.empty()) {
		t = q.front(); q.pop_front();

		for(int i=0;i<G[t].size();i++) {
			int v = G[t][i];
			mm[v].insert(t);
			if(mm[v].size() >= 2) {
				if(p[v] == 0) q.push_back(v);
				p[v] = 1;
			}
		}

	}

	int res = 0;
	for(int i=0;i<N;i++) res += p[i];
	return res;
}

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N, M;
		cin >> N;

		vector<int> G[N];
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				int u;
				cin >> u;
				if(u) {
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}

		cin >> M;
		for(int i=0;i<M;i++) {
			int u,v;
			cin >> u >> v;

			int res = solve(G, N, u, v);
			printf("%d ", res);
		}
		puts("");
	}

	return 0;
}
