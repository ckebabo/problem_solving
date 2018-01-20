#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
#include <utility>

using namespace std;

int main() {
	int grid[100][100];

	int C;
	cin >> C;

	while(C--) {
		int N;
		cin >> N;

		for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> grid[i][j];

		deque<pair<int,int> > q;
		q.push_back(make_pair(0,0));
		pair<int,int> t,tt;

		while(!q.empty()) {
			t = q.front();
			if(t.first == N-1 && t.second==N-1) break;
			q.pop_front();

			tt = t;
			tt.second += grid[tt.first][tt.second];
			if(tt.first<N && tt.second<N) {
				q.push_back(tt);
			}

			tt = t;
			tt.first += grid[tt.first][tt.second];
			if(tt.first<N && tt.second<N) {
				q.push_back(tt);
			}
		}

		if(q.empty()) {
			puts("NO");
		} else {
			puts("YES");
		}
	}

	return 0;
}
