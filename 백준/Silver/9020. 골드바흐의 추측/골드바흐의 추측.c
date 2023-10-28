#include <stdio.h>
#include <math.h>

int main(){
    int i, j, arr[10001] = { 0 };
    for(i = 2; i <= 10000; i++){
        arr[i] = i;
    }
    for(i = 2; i <= 100; i++){
        if(arr[i] != 0){
            for(j = i; j <= 10000; j += i){
                arr[j + i] = 0;
            }
        }
    }
    int c, n, num1, num2;
    scanf("%d", &c);
    while(c){
        scanf("%d", &n);
        num1 = n / 2;
        num2 = n / 2;
        if(n % 2 != 0)
            num2++;
        do{
            if(arr[num1] != 0 && arr[num2] != 0){
                printf("%d %d\n", num1, num2);
                break;
            }
            num1--;
            num2++;
        }while(1);
        c--;
    }
    return 0;
}