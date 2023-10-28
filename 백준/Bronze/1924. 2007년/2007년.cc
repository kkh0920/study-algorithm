#include <iostream>
#include <string>
using namespace std;

int main() {
	int s = 0;
	int sum = 0; 
	int num1, num2;
	string date[365];
	int day[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	cin >> num1 >> num2;
	if (num1 >= 1 && num1 <= 12 && num2 >= 1 && num2 <= 31) {
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= day[i - 1]; j++) {
				switch ((s + 1) % 7) {
				case 0:
					date[s] = "SUN";
					s++;
					break;
				case 1:
					date[s] = "MON";
					s++;
					break;
				case 2:
					date[s] = "TUE";
					s++;
					break;
				case 3:
					date[s] = "WED";
					s++;
					break;
				case 4:
					date[s] = "THU";
					s++;
					break;
				case 5:
					date[s] = "FRI";
					s++;
					break;
				case 6:
					date[s] = "SAT";
					s++;
					break;
				}
			}
		}
	}

	for (int i = 0; i < num1 - 1; i++) {
		sum += day[i];
	}

	cout << date[sum + num2 - 1] ;

	return 0;
}
