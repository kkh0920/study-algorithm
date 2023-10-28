#include <stdio.h>
#include <math.h>

int main(){
    int result, n, i, j, arr[300000] = { 0 };
    for(i = 2; i <= 270000; i++){
        arr[i] = i;
    }
    for(i = 2; i <= sqrt(270000); i++){
        if(arr[i] != 0){
            for(j = i; j <= 270000; j += i){
                arr[j + i] = 0;
            }
        }
    }
    do{
        result = 0;
        scanf("%d", &n);
        for(i = n + 1; i <= n * 2; i++){
            if(arr[i] != 0)
                result++;
        }
        if(n)
            printf("%d\n", result);
    }while(n);
    return 0;
}