#include <stdio.h>

char arr[3072][6144];

void star(int n, int x, int y);

int main(){
	
	int n, i, j;
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		for(j = 0; j < 2 * n; j++){
			arr[i][j] = ' ';	
		}
	}
	
	star(n, 0, n - 1);
	
	for(i = 0; i < n; i++){
		for(j = 0; j < 2 * n; j++){
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

void star(int n, int x, int y){
	if(n == 3){
		arr[x][y] = '*';
		arr[x + 1][y - 1] = '*';
		arr[x + 1][y + 1] = '*';
		
		int i;
		for(i = y - 2; i < y + 3; i++){
			arr[x + 2][i] = '*';
		}
	}
	
	else{
		star(n / 2, x, y); // n = 12, 0, 11
		star(n / 2, x + n / 2, y - n / 2);
		star(n / 2, x + n / 2, y + n / 2);
	}
}