#include <stdio.h>

int main(){
    int year;
    scanf("%d", &year);
    if(year % 4 == 0){
    	if(year % 100 != 0 || year % 400 == 0){
    		printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
	else{
		printf("0\n");
	}
}
