#include <stdio.h>

int main() {

	int num, c;
	int arr[11];
	
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	
	for (int i = 4; i < 11; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	
	scanf("%d", &c);

	for (int i = 0; i < c; i++) {
		scanf("%d", &num);
		printf("%d\n", arr[num]);
	}
}
