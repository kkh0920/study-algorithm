#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int num){
    int i, end;
    if(num >= 10000)
        end = 4;
    else if(num >= 1000)
        end = 3;
    else if(num >= 100)
        end = 2;
    else if(num >= 10)
        end = 1;
    else   
        end = 0;
    while(end > 0){
        if(num / int(pow(10, end)) == num % 10){
            num %= int(pow(10, end));
            num /= 10;
            end -= 2;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    int num;
    while(1){
        cin >> num;
        if(num == 0)
            break;
        if(isPalindrome(num))
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    return 0;
}
