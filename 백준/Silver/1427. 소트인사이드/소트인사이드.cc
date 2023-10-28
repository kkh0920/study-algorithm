#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {

	int num;
	char arr[11];
	int arr2[11] = { 0 };

	cin >> num;

	sprintf(arr, "%d", num);

	for (int i = 0; arr[i] != '\0'; i++) {
		arr2[i] = arr[i];
	}

	sort(arr2, arr2 + 11, compare);

	for (int i = 0; arr[i] != '\0'; i++) {
		cout << arr2[i] - '0';
	}
}