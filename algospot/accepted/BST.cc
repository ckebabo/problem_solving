#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
	int l,r,k;
};

void post(vector<node> &tree, int u, vector<int> &visit) {
	if(tree[u].l) post(tree, tree[u].l, visit);
	visit.push_back(tree[u].k);
	if(tree[u].r) post(tree, tree[u].r, visit);
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;

		int degree[105] = {0,};
		vector<node> tree(N+1);
		for(int i=1;i<=N;i++) {
			node &n = tree[i];
			cin >> n.l >> n.r >> n.k;
			degree[n.l]++;
			degree[n.r]++;
		}

		int root=0;
		for(int i=1;i<=N;i++) {
			if(degree[i]==0) { root=i; break; }
		}

		vector<int> v;
		post(tree, root, v);
		bool ans = true;
		for(int i=1;i<N;i++) {
			if(v[i-1] >= v[i]) {
				ans = false;
				break;
			}
		}

		cout << (ans ? "YES" : "NO") << endl;
	}

	return 0;
}
