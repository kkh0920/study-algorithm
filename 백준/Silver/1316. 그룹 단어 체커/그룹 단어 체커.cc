#include <iostream>
#include <string>
using namespace std;

int main() {

	int c, count = 0;
	string str;

	cin >> c; 

	for (int i = 0; i < c; i++) {
		cin >> str; 

		for (char c = 97; c <= 122; c++) {
			int j = 0;
			int cnt = 0;

			for (str[j]; j < str.length(); j++) {
				if (c == str[j]) {
					if (cnt > 0 && str[j] != str[j - 1]) {
						cnt = 0;
						break;
					}
					cnt++;
				}
			}


			if (c == str[j]) {
				if (cnt == 0 && str[j] != str[j - 1])
					break;
			}

			else {
				if (c == 122)
					count++;
			}
		}
	}
	cout << count << '\n';
}