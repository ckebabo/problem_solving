#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	const vector<int> ascending = {1,2,3,4,5,6,7,8};
	const vector<int> descending = {8,7,6,5,4,3,2,1};

	vector<int> q(8);
	for(auto &n : q) cin >> n;
	if(ascending == q) puts("ascending");
	else if(descending == q) puts("descending");
	else puts("mixed");

	return 0;
}
