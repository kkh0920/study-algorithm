#include <iostream>
#include <string.h>
using namespace std;

int main() {

	int num;
	cin >> num;
	
	if (num >= 1 && num <= 9) {
		for (int i = 1; i <= 9; i++) {
			cout << num << " * " << i << " = " << num * i << '\n';
		}
	}
	

}
