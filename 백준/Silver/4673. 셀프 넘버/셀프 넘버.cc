#include <iostream>
using namespace std;

int main() {
	
	int arr[10000];

	for (int i = 1; i <= 10000; i++) {
		arr[i - 1] = i;
	}

	for (int i = 1; i <= 10000; i++) {
		int num;

		for (int j = 0; j < 10000; j++) {
				
            num = i + i / 1000 + (i % 1000) / 100 + (i % 1000 % 100) / 10 + i % 1000 % 100 % 10;

			if (arr[j] == num) {
				arr[j] = 0;
				break;
			}
			
		}
	}

	for (int i = 0; i < 10000; i++) {
		if (arr[i] != 0)
			cout << arr[i] << '\n';
	}

}