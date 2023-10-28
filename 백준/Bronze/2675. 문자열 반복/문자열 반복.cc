#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int c, rep;
	string str;

	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> rep >> str;
		for (int j = 0; j < str.length(); j++) {
			for (int s = 0; s < rep; s++) {
				cout << str[j];
			}
		}
        cout << '\n';
	}
}