#include <stdio.h>

int main(){
    
    int i, j, n, m, arr[100][100], num;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &num);
            arr[i][j] += num;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}