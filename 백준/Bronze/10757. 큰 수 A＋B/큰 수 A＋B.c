#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char arr[3][10002] = { '\0' };
    int i, longer, shorter, result[10001] = { 0 };
    scanf("%s %s" , arr[0], arr[1]);
    if(strlen(arr[0]) > strlen(arr[1])){
        longer = 0;
        shorter = 1;
    }
    else{
        longer = 1;
        shorter = 0;
    }
    int number = strlen(arr[0]) - strlen(arr[1]);
    int num = abs(number);
    for(i = 0; i < num; i++){
        arr[2][i] = '0';
    }
    for(i = num; arr[shorter][i - num] != '\0'; i++){
        arr[2][i] = arr[shorter][i - num];
    }
    shorter = 2;
    int leng = strlen(arr[longer]);
    for(i = leng; i >= 1; i--){
        num = arr[longer][i - 1] + arr[shorter][i - 1] - 96;
        if(num >= 10){
            num -= 10;
            result[i - 1] += 1;
        }
        result[i] += num;
        if(result[i] >= 10){
            result[i] -= 10;
            result[i - 1] += 1;
        }
    }
    if(result[0] != 0)
        printf("1");
    for(i = 1; i <= leng; i++){
        printf("%d", result[i]);
    }
    printf("\n");
    return 0;
}