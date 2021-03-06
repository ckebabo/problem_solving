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
		if(n!=2 && n%2==0) { d.insert(2); d.insert(n/2); }
		for(int i=sqrt(n)+1;i>2;i--) {
			if(n%i == 0) { d.insert(i); d.insert(n/i); }
		}

		bool ans = false;
		bool t[500001] = {false,};
		t[0] = true;
		if(accumulate(d.begin(), d.end(), 0) > n) {
			ans = true;
			for(auto v : d) {
				for(int i=n-v;i>=0;i--) {
					if(t[i]) t[i+v] = true;
				}
			}
			if(t[n]) ans=false;
		}

		cout << (ans ? "" : "not ") << "weird" << endl;
	}

	return 0;
}
