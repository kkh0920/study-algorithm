#include <stdio.h>
#include <math.h>

void move(int from, int to){
    printf("%d %d\n", from, to);
}

void hanoi(int num, int from, int by, int to){
    if(num == 1) move(from, to);
    
    else{
        hanoi(num - 1, from, to, by);
        move(from, to);
        hanoi(num - 1, by, from, to);
    }
}

int main(){
    int num, count;
    scanf("%d", &num);
    
    count = pow(2, num) - 1;
    
    printf("%d\n", count);
    hanoi(num, 1, 2, 3);
}