#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T;

	map<string, int> weekdays;
	weekdays["Sunday"] = 0;
	weekdays["Monday"] = 1;
	weekdays["Tuesday"] = 2;
	weekdays["Wednesday"] = 3;
	weekdays["Thursday"] = 4;
	weekdays["Friday"] = 5;
	weekdays["Saturday"] = 6;

	int days[] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	while(T--) {
		int m,d,dd;
		string day;

		cin >> m >> d >> day;
		dd = weekdays[day];

		if(d-dd < 0) {
			m -= 1;
			d = days[m]+(d-dd);
		} else {
			d -= dd;
		}

		for(int i=0;i<7;i++) {
			printf("%d ", d);
			d += 1;
			if(d>days[m]) {
				d = 1;
				m = (m+1)%13;
			}
		}
		puts("");
	}

	return 0;
}
