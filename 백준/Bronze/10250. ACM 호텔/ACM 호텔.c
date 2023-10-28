#include <stdio.h>

int main(){
    
    int t, h, w, n;
    scanf("%d", &t);
    while(t){
        scanf("%d %d %d", &h, &w, &n);
        if(n % h == 0)
            printf("%d\n", 100 * h + n/h);
        else
            printf("%d\n", 100 * (n % h) + n/h + 1);
        t--;
    }
    return 0;
}