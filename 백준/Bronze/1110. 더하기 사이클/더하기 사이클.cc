#include <iostream>
using namespace std;

int main() {

	int num, cycle = 100, count = 1;

	cin >> num;

	cycle = (((num / 10) + (num % 10)) % 10) + (num % 10 * 10);

	while(num != cycle){
		cycle = (((cycle / 10) + (cycle % 10)) % 10) + (cycle % 10 * 10);
		count++;
	}

	cout << count;
}