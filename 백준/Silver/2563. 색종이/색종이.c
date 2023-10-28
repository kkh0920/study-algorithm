#include <stdio.h>

int main(){
    
    int i, j, k, num, x, y, arr[100][100] = { 0 }, result = 0;
    scanf("%d", &num);
    for(i = 0; i < num; i++){
        scanf("%d %d", &x, &y);
        for(j = x; j < x + 10; j++){
            for(k = y; k < y + 10; k++){
                if(arr[j][k] == 0){
                    arr[j][k] = 1;
                    result++;
                }
            }
        }
    }
    printf("%d\n", result);
    return 0;
}