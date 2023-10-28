#include <stdio.h>

int main(){
	
	int Number, Score1, Score2 = 0;
	
	for(int i = 1; i <= 5; i++){
		int Score_Sum = 0;
		for(int j = 0; j < 4; j++){
			scanf("%d", &Score1);
			Score_Sum += Score1;
		}
		if(Score_Sum >= Score2){	
			Score2 = Score_Sum;
			Number = i;
		}
	}
	
	printf("%d %d", Number, Score2);
}