#include <stdio.h>

int main(){
    
    int i, num, arr[42] = { 0 }, result = 0;
    for(i = 0; i < 10; i++){
        scanf("%d", &num);
        if(arr[num % 42] != 1){
            arr[num % 42] = 1;
            result++;
        }
    }
    printf("%d\n", result);
    return 0;
}