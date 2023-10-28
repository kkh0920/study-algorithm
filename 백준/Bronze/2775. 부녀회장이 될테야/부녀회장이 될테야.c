#include <stdio.h>

int main(){
    
    int num, i, j, c, k, n, arr[15][15] = { 0 };
    for(i = 0; i < 15; i++){
        arr[i][0] = 1;
        arr[0][i] = i + 1;
    }
    for(i = 1; i < 15; i++){
        num = 1;
        for(j = 1; j < 15; j++){
            num += arr[i - 1][j];
            arr[i][j] = num;
        }
    }
    scanf("%d", &c);
    while(c){
        scanf("%d %d", &k, &n);
        printf("%d\n", arr[k][n - 1]);
        c--;
    }
    return 0;
}