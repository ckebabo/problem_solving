#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, vector<int> > cache;
int f[100005] = {0,};

vector<int> tree(int n) {
	vector<int> &r = cache[n];

	if(!r.empty()) return r;

	map<int, vector<int> >::iterator it;
	for(;;) {
		it = cache.find(n);
		if(it != cache.end() && !it->second.empty()) {
			r.insert(std::end(r), std::begin(it->second), std::end(it->second));
			break;
		} else {
			r.push_back(n);
		}

		n = f[n];
	}

	return r;
}

int main() {
	int C;
	cin >> C;

	while(C--) {
		int N, Q;
		cin >> N >> Q;

		for(int i=1;i<N;i++) scanf("%d", f+i);

		cache.clear();
		cache[0] = {0};

		for(int i=0;i<Q;i++) {
			int a,b;
			scanf("%d %d", &a, &b);

			vector<int> aa = tree(a);
			vector<int> bb = tree(b);

			reverse(aa.begin(), aa.end());
			reverse(bb.begin(), bb.end());

			int ans = abs(int(aa.size() - bb.size()));
			for(int i=0;i<aa.size();i++) {
				if(aa[i] != bb[i]) {
					ans = aa.size()-i + bb.size()-i;
					break;
				}
			}

			printf("%d\n", ans);
		}
	}

	return 0;
}
