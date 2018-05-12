#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int C;
	cin >> C;

	map<string, int> sm = {{"zero", 0}, {"one", 1}, {"two", 2},
		{"three", 3}, {"four", 4}, {"five", 5}, {"six", 6},
		{"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10}};
	while(C--) {
		string a, b, eq, c;
		char op;
		cin >> a >> op >> b >> eq >> c;

		int ia, ib, ic;
		ia = sm[a];
		ib = sm[b];
		switch(op) {
		case '+': ic = ia+ib; break;
		case '-': ic = ia-ib; break;
		case '*': ic = ia*ib; break;
		}

		string ans = "No";
		if(0<=ic && ic<=10) {
			sort(c.begin(), c.end());
			for(auto it=sm.begin(); it!=sm.end(); ++it) {
				if(it->second == ic) {
					string a = it->first;
					sort(a.begin(), a.end());
					if(c == a) {
						ans = "Yes";
					}
					break;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
