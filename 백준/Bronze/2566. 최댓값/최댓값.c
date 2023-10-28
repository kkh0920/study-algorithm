#include <stdio.h>

int main(){
    
    int i, j, max = 0, num2, x, y;
    for(i = 1; i <= 9; i++){
        for(j = 1; j <= 9; j++){
            scanf("%d", &num2);
            if(max <= num2){
                x = i;
                y = j;
                max = num2;
            }
        }
    }
    printf("%d\n%d %d\n", max, x, y);

    return 0;
}