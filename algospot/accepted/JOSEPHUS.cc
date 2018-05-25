#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		int N,M;
		cin >> N >> M;

		list<int> l;
		for(int i=1;i<=N;i++) l.push_back(i);

		auto it = l.begin();
		for(;;) {
			it = l.erase(it);
			if(it == l.end()) it = l.begin();
			N--;
			if(N==2) break;

			for(int i=1;i<M;i++) {
				++it;
				if(it == l.end()) it = l.begin();
			}
		}

		for(auto& n : l) printf("%d ", n); puts("");
	}

	return 0;
}
