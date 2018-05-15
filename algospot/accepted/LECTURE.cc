#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		multiset<string> ss;
		for(int i=0;i<s.size();i+=2) {
			ss.insert(s.substr(i, 2));
		}

		for(auto &s : ss) printf("%s", s.c_str()); puts("");
	}

	return 0;
}
