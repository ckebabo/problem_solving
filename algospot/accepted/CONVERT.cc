#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	int N;
	cin >> N;
	for(int cs=1;cs<=N;cs++) {
		double v;
		string unit;
		cin >> v >> unit;

		if(unit == "kg") {
			v *= 2.2046;
			unit = "lb";
		} else if(unit == "lb") {
			v *= 0.4536;
			unit = "kg";
		} else if(unit == "l") {
			v *= 0.2642;
			unit = "g";
		} else if(unit == "g") {
			v *= 3.7854;
			unit = "l";
		}

		printf("%d %.4lf %s\n", cs, v, unit.c_str());
	}

	return 0;
}
