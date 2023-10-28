#include <stdio.h>

int main(){
    
    int a, b, v, r;
    scanf("%d %d %d", &a, &b, &v);
    r = (v - a)/(a - b) + 1;
    if((v - a) % (a - b) != 0)
        r++;
    printf("%d\n", r);
    return 0;
}