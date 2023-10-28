#include <stdio.h>

int main(){
	
	int h, m;
	
	scanf("%d %d", &h, &m);
	
	if(m - 45 < 0){
		if(h - 1 >= 0)
			printf("%d %d\n", h - 1, 60 + (m - 45));
		
		else
			printf("%d %d\n", 23, 60 + (m - 45));	
	}
	
	else{
		printf("%d %d\n", h, m - 45);
	}
}