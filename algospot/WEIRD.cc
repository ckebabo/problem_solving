#include <iostream>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;

		set<int> d;
		d.insert(1);
		for(int i=sqrt(n)+1;i>=2;i--) {
			if(n%i == 0) { d.insert(i); d.insert(n/i); }
		}

		bool ans = true;
		if(accumulate(d.begin(), d.end(), 0) > n) {
			set<int> k;
			k.insert(0);
			for(auto v : d) {
				set<int> kk = k;
				for(auto s : k) {
					kk.insert(s+v);
				}
				k = kk;

				if(k.find(n) != k.end()) {
					ans = false;
					break;
				}
			}
		}

		cout << (ans ? "" : "not ") << "weird" << endl;
	}

	return 0;
}
