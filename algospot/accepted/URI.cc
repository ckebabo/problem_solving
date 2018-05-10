#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		string s;
		cin >> s;
		for(int i=0;i<s.size();i++) {
			if(s[i]=='%') {
				if(i+2 < s.size() && s[i+1]=='2') {
					switch(s[i+2]) {
					case '0': putc(' ', stdout); i+=2; break;
					case '1': putc('!', stdout); i+=2; break;
					case '4': putc('$', stdout); i+=2; break;
					case '5': putc('%', stdout); i+=2; break;
					case '8': putc('(', stdout); i+=2; break;
					case '9': putc(')', stdout); i+=2; break;
					case 'a': putc('*', stdout); i+=2; break;
					default:  putc('%', stdout); i+=2; break;
					}
				} else{
					putc(s[i], stdout);
				}
			} else {
				putc(s[i], stdout);
			}
		}
		puts("");
	}

	return 0;
}
