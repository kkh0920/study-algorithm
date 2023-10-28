#include <iostream>
using namespace std;

const int mod = 1000000;
const int p = mod / 10 * 15;
int fibonacci[p] = { 0, 1, };

int main() {

	long long num;
	
	cin >> num;

	for (int i = 2; i < p; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		fibonacci[i] %= mod;
	}

	cout << fibonacci[num%p] << '\n';
}