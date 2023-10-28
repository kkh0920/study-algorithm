#include <stdio.h>

int main(){
    int i, j, c, n, arr[41];
    arr[0] = 0;
    arr[1] = 1;
    for(i = 2; i < 41; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    scanf("%d", &c);
    while(c){
        scanf("%d", &n);
        if(n == 0){
            printf("1 0\n");
            c--;
            continue;
        }
        printf("%d %d\n", arr[n - 1], arr[n]);
        c--;
    }
    return 0;
}