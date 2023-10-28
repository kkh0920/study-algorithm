#include <stdio.h>

int main(){

    int i, num, x = 1;
    scanf("%d", &num);
    for(i = 0; x < num; i++){
        x += 6 * i;
    }
    if(num == 1)
        i++;
    printf("%d\n", i);
    return 0;
}