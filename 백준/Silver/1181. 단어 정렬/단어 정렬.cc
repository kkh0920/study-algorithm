#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

int main(void) {
	
	int num;
	string arr[20000];

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + num, compare);

	for (int i = 0; i < num; i++) {
		if (i > 0 && arr[i] == arr[i - 1])
			continue;
		else
			cout << arr[i] << '\n';
	}
}