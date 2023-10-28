#include <stdio.h>

int main(){
	
	int arr[10];
	
	for(int i = 1; i <= 9; i++){
		scanf("%d", &arr[i]);
	}
	
	int max = arr[1];
	int num = 1;
	int Case = 1;
	
	for(int i = 1; i < 9; i++){
		if(arr[i + 1] > arr[Case]){
			max = arr[i + 1];
			num = i + 1;
			Case = i + 1;		
		}	
	}
	
	printf("%d\n", max);
	printf("%d\n", num);
}