#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		int N;
		cin >> N;

		vector<int> G[30];
		int in[30] = {0,};
		string a, b;
		cin >> a;
		for(int i=1;i<N;i++) {
			string b;
			cin >> b;
			for(int j=0; j<min(a.size(), b.size()); j++) {
				if(a[j] != b[j]) {
					G[a[j]-'a'].push_back(b[j]-'a');
					in[b[j]-'a'] += 1;
					break;
				}
			}
			a = b;
		}

		string ans;
		for(int i=0;i<='z'-'a';i++) {
			if(in[i] == 0) ans += 'a'+i;
		}
		for(int p=0;p < ans.size(); p++) {
			int u = ans[p]-'a';
			for(int i=0;i<G[u].size();i++) {
				int v = G[u][i];
				in[v] -= 1;
				if(in[v] == 0) {
					ans += v+'a';
				}
			}
		}

		if(ans.size() == 26) {
			cout << ans << endl;;
		} else {
			cout << "INVALID HYPOTHESIS" << endl;;
		}
	}

	return 0;
}
