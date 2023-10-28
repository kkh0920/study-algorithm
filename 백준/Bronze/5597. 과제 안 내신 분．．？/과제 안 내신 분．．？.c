#include <stdio.h>

int main(){
    
    int i, num, chk[30] = { 0 };
    for(i = 0; i < 28; i++){
        scanf("%d", &num);
        chk[num - 1] = 1;
    }
    for(i = 0; i < 30; i++){
        if(chk[i] == 0)
            printf("%d\n", i + 1);
    }
    return 0;
}