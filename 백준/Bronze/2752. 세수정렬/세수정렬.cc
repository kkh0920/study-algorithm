#include <iostream>
using namespace std;

int main() {

	int arr[4];

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (arr[j] < arr[i]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << arr[i] << ' ';
	}
}