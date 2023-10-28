#include <stdio.h>

int main(){
    
    int i, num, arr[6] = { 1, 1, 2, 2, 2, 8 };

    for(i = 0; i < 6; i++){
        scanf("%d", &num);
        arr[i] -= num;
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}