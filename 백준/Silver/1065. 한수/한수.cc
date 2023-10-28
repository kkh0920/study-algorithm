#include <iostream>
using namespace std;

int func(int x) {
	
	int num2, num3, count = 0;

	for (int i = 111; i <= x; i++) {
		num2 = (i / 100) - (i % 100) / 10;
		num3 = (i % 100) / 10 - (i % 100 % 10);

		if (num2 == num3)
			count++;
	}

	if (x < 99)
		return x;

	else
		return count + 99;
}

int main() {
	
	int num;

	cin >> num;

	cout << func(num) << '\n';
}