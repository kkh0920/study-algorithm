#include <stdio.h>

int main(){
	
	char arr[8][5] = { {"ABC"}, {"DEF"}, {"GHI"}, {"JKL"}, {"MNO"}, {"PQRS"}, {"TUV"}, {"WXYZ"} };
	char arr2[16];
	
	scanf("%s", arr2);
	
	int s, i, j, sum = 0;
	for(s = 0; arr2[s] != '\0'; s++){
		for(i = 0; i < 8; i++){
			for(j = 0; j < 5; j++){
				if(arr2[s] == arr[i][j]){
					sum += i + 3;
				}
			}
		}
	}
	
	printf("%d\n", sum);
	
	return 0;
}