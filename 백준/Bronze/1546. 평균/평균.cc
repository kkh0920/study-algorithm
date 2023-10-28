#include <iostream>
using namespace std;

int main() {

	double num, max;
	double sum = 0;
	int score[1000];
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> score[i]; 

		if (score[i] > 100 || score[i] < 0) {
			break;
		}

	}
	
	max = score[0];

	for (int j = 0; j < num; j++) {
		if (score[j] > max)
			max = score[j]; 
	}

	for (int s = 0; s < num; s++) {
		sum += (score[s] / max) * 100;
	}

	cout << sum / num;

}
