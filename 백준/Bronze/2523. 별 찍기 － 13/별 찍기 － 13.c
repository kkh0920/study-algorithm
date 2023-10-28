#include <stdio.h>

int main(){
	
	int num, c, i, j;
	
	scanf("%d", &num);
	
	c = 2 * num - 1;
	
	for(i = 0; i < num; i++){
		for(j = 0; j <= i; j++){
			printf("*");
		}
		printf("\n");
	}
	
	for(i = 0; i < c / 2; i++){
		for(j = i; j < c / 2; j++){
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}