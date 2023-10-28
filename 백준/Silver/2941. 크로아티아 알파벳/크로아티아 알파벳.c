#include <stdio.h>

int main(){
    
    char arr[101] = { '\0' };
    int i, result = 0;
    scanf("%s", arr);
    for(i = 0; arr[i + 1] != '\0'; i++){
        switch (arr[i]){
            case 'c':
                if(arr[i + 1] == '=' || arr[i + 1] == '-'){
                    i++;
                }
                break;
            case 'd':
                if(arr[i + 1] == 'z' && arr[i + 2] == '='){
                    i += 2;
                }
                else if(arr[i + 1] == '-'){
                    i++;
                }
                break;
            case 'l':
            case 'n':
                if(arr[i + 1] == 'j'){
                    i++;
                }
                break;
            case 's':
            case 'z':
                if(arr[i + 1] == '='){
                    i++;
                }
                break;
        }
        result++;
    }
    if(arr[i] != '\0')
        result++;
    printf("%d\n", result);
    return 0;
}