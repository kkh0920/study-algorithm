#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string str;

	getline(cin, str);

	for (char a = 97; a <= 122; a++) {
		int cnt = 0;

		for (int i = 0; i < str.length(); i++) {
			if (a == str[i]) {
				cout << i << ' ';
				break;
			}
			else
				cnt++;
		}
		if (cnt == str.length())
			cout << -1 << ' ';
	}
}