#include <iostream>
using namespace std;

int main(){

    int num1, num2, num3;
    cin >> num1 >> num2;
    cin >> num3;

    num2 += num3;
    if(num2 >= 60){
        num1 += num2 / 60;
        if(num1 >= 24){
            num1 %= 24;
        }
        num2 %= 60;
    }

    cout << num1 << ' ' << num2 << '\n'; 

    return 0;
}
