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

		int t[100][100] {{0,},};
		t[0][0] = 1;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(t[i][j]) {
					int y = i+grid[i][j];
					int x = j+grid[i][j];
					if(x<N) t[i][x] = 1;
					if(y<N) t[y][j] = 1;
				}
			}
		}

		if(t[N-1][N-1] == 0) {
			puts("NO");
		} else {
			puts("YES");
		}
	}

	return 0;
}
