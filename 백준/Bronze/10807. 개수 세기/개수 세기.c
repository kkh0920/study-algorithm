#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int i, c, num, *arr, result = 0;
    scanf("%d", &c);
    arr = (int*)malloc(sizeof(int) * c);
    for(i = 0; i < c; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &num);
    for(i = 0; i < c; i++){
        if(arr[i] == num)
            result++;
    }
    printf("%d\n", result);
    free(arr);
    return 0;
}