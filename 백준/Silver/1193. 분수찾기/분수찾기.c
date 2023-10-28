#include <stdio.h>

int main(){
    int i, j, num, a = 1;
    scanf("%d", &num);
    if(num == 1){
        printf("1/1\n");
        return 0;
    }
    for(i = 0; a <= num; i++){
        a += i;
    }
    i--;
    j = i;
    a -= i;
    num -= a;
    if(i % 2 == 1){
        j = 1;
        i -= num;
        j += num;
    }
    else{
        i = 1;
        i += num;
        j -= num;
    }

    printf("%d/%d\n", i, j);

    return 0;
}