#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	int N;
	cin >> N;
	for(int cs=1;cs<=N;cs++) {
		int R,C;
		string msg;
		cin >> R >> C; getc(stdin);
		getline(cin, msg);

		string s;
		for(auto c : msg) {
			if(c==' ') s += "00000";
			else {
				int n = c-'A'+1;
				for(int k=0x10;k>0;k>>=1) {
					if(n&k) s += '1'; else s+='0';
				}
			}
		}
		for(int i=s.size();i<R*C;i++) s += '0';

		char m[25][25] = {{0,},};
		pair<int,int> dir[] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
		int d=0;
		int x=0,y=0;
		int end=R*C;
		for(int p=0;p<end;p++) {
			m[y][x] = s[p];

			y += dir[d].first;
			x += dir[d].second;
			if(y<0 || x<0 || y>=R || x>=C || m[y][x]!=0) {
				y -= dir[d].first;
				x -= dir[d].second;

				d = (d+1)%4;
				y += dir[d].first;
				x += dir[d].second;
			}
		}

		printf("%d ", cs);
		for(int i=0;i<R;i++) cout << m[i];
		puts("");
	}

	return 0;
}
