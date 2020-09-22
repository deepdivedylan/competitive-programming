#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
	int cases;
	cin >> cases;

	while (cases > 0) {
		stringstream answer;
		int largeNumber;
		cin >> largeNumber;

		int limit = (int)ceil(log10(largeNumber));
		int terms = 0;
		for (int i = limit; i > 0; i--) {
			int thisDigit = (largeNumber % (int)pow(10, i)) / pow(10, i - 1);

			// EXCEPTION: if the large number is a perfect power of 10, return
			if (i == limit && largeNumber % (int)pow(10, i) == 0) {
				answer << largeNumber;
				terms++;
				break;
			}

			// normal case: extract out each non zero term
			if (thisDigit != 0) {
				answer << thisDigit * (int)pow(10, i - 1) << " ";
				terms++;
			}
		}
		cout << terms << endl << answer.str() << endl;
		cases--;
	}

	return 0;
}
