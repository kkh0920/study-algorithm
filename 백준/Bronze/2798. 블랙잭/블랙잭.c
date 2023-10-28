#include <stdio.h>

int main(){
    int k, i, j, n, m, max = 0, sum;
    scanf("%d %d", &n, &m);
    int num[n];
    for(i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    int first = 0, second = 1, thrid = 2;
    for(k = first; k < n - 2; k++){
        for(i = second; i < n - 1; i++){
            for(j = thrid; j < n; j++){
                sum = num[first] + num[second] + num[j];
                if(sum >= max && sum <= m){
                    max = sum;
                }
                if(max == m){
                    printf("%d\n", max);
                    return 0;
                }
            }
            second++;
            thrid++;
        }
        first++;
        second = first + 1;
        thrid = first + 2;
    }
    printf("%d\n", max);
    return 0;
}