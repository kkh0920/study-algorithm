#include <stdio.h>

char arr[2187][2188];

void star(int n, int x, int y);

int main(){
	
	int n, i, j;
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n + 1; j++){
			arr[i][j] = ' ';	
		}
	}
	
	star(n, 0, 0);
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%c", arr[i][j]);	
		}
		printf("\n");
	}
    
	return 0;
}

void star(int n, int x, int y){
	if(n == 3){
		int i, j;
		for(i = x; i < x + 3; i++){
			for(j = y; j < y + 3; j++){
				arr[i][j] = '*';
			}
		}
		arr[x + 1][y + 1] = ' ';
		return;
	}
	
	int s, k;
	for(int s = 0; s < 3; s++){
		for(int k = 0; k < 3; k++){
			if(s == 1 && k == 1) 
				k++;				
			star(n / 3, x + (n / 3) * s, y + (n / 3) * k);
		}
	}		
}