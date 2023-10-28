#include <iostream>
using namespace std;

int main() {

	int num, cmp;
	cin >> num;

	cmp = (num % 5) % 3;

	int i;

	for (i = 0; cmp != 0; i++) {
		if (num % 5 + 5 * i > num) {
			cout << -1;
			break;
		}
		cmp = ((num % 5) + 5 * i) % 3;
	}

	if (num % 5 + 5 * i <= num)
		cout << ((num % 5) + 5 * i) / 3 + (num - ((num % 5) + 5 * i)) / 5;

	else if (num >= 3 && num % 3 == 0)
		cout << num / 3;
	
}
