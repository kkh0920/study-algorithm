#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int getSum(string a) {
	int sum = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		if (getSum(a) != getSum(b)) 
			return getSum(a) < getSum(b);
		else
			return a < b;
	}	
		
	else
		return a.length() < b.length();
}

int main(void) {
	
	int num;
	string arr[1000];

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + num, compare);

	for (int i = 0; i < num; i++) {
		cout << arr[i] << '\n';
	}
}