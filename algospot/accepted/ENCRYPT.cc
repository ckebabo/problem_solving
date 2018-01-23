#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		string s;
		cin >> s;

		for(int i=0;i<s.size();i+=2) putc(s[i], stdout);
		for(int i=1;i<s.size();i+=2) putc(s[i], stdout);
		puts("");
	}

	return 0;
}
