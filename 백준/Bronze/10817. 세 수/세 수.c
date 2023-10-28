#include <stdio.h>

int main(){
	
	int A, B, C, secMax, large, small;
		
	scanf("%d %d %d", &A, &B, &C);
	
	if(A > B){
		large = A;
		small = B;
	}
	else{
		large = B;
		small = A;
	}

	if(large < C){
		secMax = large;
	}
	else{
		if(small > C)
			secMax = small;
		else
			secMax = C;
	}
	
	printf("%d\n", secMax);
	return 0;
}