#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
	
	int num1, num2, i, s;
	char a[5], b[5], c[4];

	cin >> num1 >> num2;

	sprintf(a, "%d", num1);
	sprintf(b, "%d", num2);

	int t = 2;
	for (int i = 0; i < 3; i++) {
		c[i] = a[t];
		t--;
	}
	
	i = atoi(c);

	t = 2;
	for (int i = 0; i < 3; i++) {
		c[i] = b[t];
		t--;
	}

	s = atoi(c);

	if (i > s)
		cout << i;
	else
		cout << s;
}