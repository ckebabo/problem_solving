#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main() {
	int M, N;
	cin >> M >> N; getc(stdin);

	vector<string> docs(M);
	for(auto &s : docs) getline(cin, s);

	int ans = 0;
	for(int i=0;i<N;i++) {
		string s;
		getline(cin, s);
		for(int j=0;j<M;j++) {
			if(strncmp(s.c_str(), docs[j].c_str(), s.size()) == 0) {
				ans += 1;
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
