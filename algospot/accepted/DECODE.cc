#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int N;
	cin >> N;

	for(int cs=1;cs<=N;cs++) {
		int R,C;
		string s;
		cin >> R >> C >> s;

		vector<string> m;
		for(int i=0;i<R*C;i+=C) {
			m.push_back(s.substr(i, C));
		}

		s.clear();

		pair<int,int> dir[] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
		int d=0;
		int x=0,y=0;
		int end=R*C;
		while(end--) {
			s += m[y][x];
			m[y][x] = '2';

			y += dir[d].first;
			x += dir[d].second;
			if(y<0 || x<0 || y>=R || x>=C || m[y][x]=='2') {
				y -= dir[d].first;
				x -= dir[d].second;

				d = (d+1)%4;
				y += dir[d].first;
				x += dir[d].second;
			}
		}

		m.clear();
		for(int i=0;i<s.size();i+=5) {
			m.push_back(s.substr(i, 5));
		}
		printf("%d ", cs);
		for(auto s : m) {
			if(s.size() < 5) continue;
			int n = 0;
			for(int i=0; i<s.size();i++) {
				n = n*2 + (s[i]-'0');
			}
			if(n==0) putc(' ', stdout);
			else putc('A'+n-1, stdout);
		}
		puts("");
	}

	return 0;
}
