#include <stdio.h>
#include <string.h>

void str_upper(char *s) {

	int i;
	int count = 0;
    int strLen = strlen(s);
	for (i = 0; i < strLen; i++) {
		if( s[i] >='a' && s[i] <= 'z' )
		s[i] = s[i]-'a'+'A';
	}
}



int main(){
    
    char str[1000001] = { '\0' };
    int arr[26] = { 0 }, i, max = 0, maxI = 0, cnt = 0;
    scanf("%s", str);
    str_upper(str);
    for(i = 0; str[i] != '\0'; i++){
        arr[str[i] - 65]++;
    }
    for(i = 0; i < 26; i++){
        if(arr[i] > max){
            max = arr[i];
            maxI = i;
        }
    }
    for(i = 0; i < 26; i++){
        if(max == arr[i]){
            cnt++;
            if(cnt == 2){
                printf("?\n");
                return 0;
            }
        }
    }
    printf("%c\n", maxI + 65);
    return 0;
}