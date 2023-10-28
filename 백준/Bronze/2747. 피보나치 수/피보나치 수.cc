#include <iostream>
using namespace std;

int main() {

	int num;
	int fibonacci[46];

	cin >> num;

	fibonacci[0] = 0;
	fibonacci[1] = 1;

	for (int i = 2; i <= num; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	cout << fibonacci[num] << '\n';
}