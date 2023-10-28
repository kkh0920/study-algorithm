#include <math.h>

int main(){
    int m, n, i, j, arr[1001000] = { 0 };
    scanf("%d %d", &m, &n);
    for(i = 2; i <= n; i++){
        arr[i] = i;
    }
    for(i = 2; i <= sqrt(n); i++){
        if(arr[i] != 0){
            for(j = i; j <= n; j += i){
                arr[j + i] = 0;
            }
        }
    }
    for(i = m; i <= n; i++){
        if(arr[i] != 0)
            printf("%d\n", arr[i]);
    }
    return 0;
}