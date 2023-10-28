#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    char arr[8] = { '\0' };
    int i, j, k, sum, num;
    scanf("%d", &num);
    for(k = 0; k < num; k++){
        j = 0;
        sum = 0;
        sprintf(arr, "%d", k);
        for(i = 0; arr[i] != '\0'; i++){
            sum += arr[i] - '0';
        }
        for(i -= 1; i >= 0; i--){
            sum += (arr[i] - '0') * pow(10, j);
            j++;
        }
        if(sum == num){
            printf("%d\n", k);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}