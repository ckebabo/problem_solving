#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int M, N;
	cin >> M >> N;

	vector<string> m(N);
	for(auto &s : m) cin >> s;

	map<pair<int,int>, int> dist;
	multimap<int, pair<int,int> > mm;

	dist[make_pair(0,0)] = 0;
	mm.insert(make_pair(0, make_pair(0,0)));

	while(!mm.empty()) {
		auto it = mm.begin();
		mm.erase(it);

		auto pos = it->second;
		int d = it->first;

		if(pos.first>0) {
			auto it2 = dist.find(make_pair(pos.first-1, pos.second));
			int dd = (m[pos.first-1][pos.second]=='1' ? d+1 : d);
			if(it2 == dist.end() || it2->second>dd) {
				auto p = make_pair(pos.first-1, pos.second);
				mm.insert(make_pair(dd, p));
				dist[p] = dd;
			}
		}
		if(pos.first<N-1) {
			auto it2 = dist.find(make_pair(pos.first+1, pos.second));
			int dd = (m[pos.first+1][pos.second]=='1' ? d+1 : d);
			if(it2 == dist.end() || it2->second>dd) {
				auto p = make_pair(pos.first+1, pos.second);
				mm.insert(make_pair(dd, p));
				dist[p] = dd;
			}
		}
		if(pos.second>0) {
			auto it2 = dist.find(make_pair(pos.first, pos.second-1));
			int dd = (m[pos.first][pos.second-1]=='1' ? d+1 : d);
			if(it2 == dist.end() || it2->second>dd) {
				auto p = make_pair(pos.first, pos.second-1);
				mm.insert(make_pair(dd, p));
				dist[p] = dd;
			}
		}
		if(pos.second<M-1) {
			auto it2 = dist.find(make_pair(pos.first, pos.second+1));
			int dd = (m[pos.first][pos.second+1]=='1' ? d+1 : d);
			if(it2 == dist.end() || it2->second>dd) {
				auto p = make_pair(pos.first, pos.second+1);
				mm.insert(make_pair(dd, p));
				dist[p] = dd;
			}
		}
	}

	cout << dist[make_pair(N-1, M-1)] << endl;

	return 0;
}
