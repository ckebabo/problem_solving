#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		int N,M;
		cin >> N >> M;

		vector<int> G[30];
		int in[30] = {0,};
		while(M--) {
			string s;
			cin >> s;
			G[s[0]-'A'].push_back(s[1]-'A');
			in[s[1]-'A'] += 1;
		}

		string ans;
		while(ans.size() < N) {
			for(int i=0;i<N;i++) {
				if(in[i] != 0) continue;

				ans += 'A' + i;
				in[i] -= 1;

				int u = i;
				for(int j=0;j<G[u].size();j++) {
					int v = G[u][j];
					in[v] -= 1;
				}
				
				break;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
