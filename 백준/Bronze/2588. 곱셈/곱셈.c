#include <stdio.h>

int main(){
	
	int num1, num2, result, prc1, prc2, prc3;
	
	scanf("%d%d", &num1, &num2);

	prc1 = num1 * (num2 % 10);
	prc2 = num1 * ((num2 % 100) / 10);
	prc3 = num1 * (num2 / 100);
	result = num1 * num2;
	
	printf("%d\n", prc1);
	printf("%d\n", prc2);
	printf("%d\n", prc3);
	printf("%d\n", result);
	
	return 0;
}