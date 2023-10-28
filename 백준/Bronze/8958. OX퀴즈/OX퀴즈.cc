#include <iostream>
#include <string>
using namespace std;

int main() {
	
	int c;
	string str;

	cin >> c;

	for (int i = 0; i < c; i++) {
		int score = 0;
		int s = 1;
		
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'O') {
				score += s;
				s++;
			}
			else
				s = 1;
		}
		cout << score << '\n';
	}
}