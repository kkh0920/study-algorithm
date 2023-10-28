#include <stdio.h>

int main(){
    
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    if(num1 == num2){
        scanf("%d", &num2);
        if(num1 == num2)
            printf("%d\n", 10000 + num1 * 1000);
        else   
            printf("%d\n", 1000 + num1 * 100);
    }
    else{
        int num3;
        scanf("%d", &num3);
        if(num1 == num3 || num2 == num3)
            printf("%d\n", 1000 + num3 * 100);
        else if(num1 > num2 && num1 > num3)
            printf("%d\n", num1 * 100);
        else if(num2 > num1 && num2 > num3)
            printf("%d\n", num2 * 100);
        else
            printf("%d\n", num3 * 100);
    }
    
    return 0;
}