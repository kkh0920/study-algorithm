#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int i, num1, num2, min, max, res1, res2;
    cin >> num1 >> num2;
    min = num1 > num2 ? num2 : num1;
    max = num1 > num2 ? num1 : num2;
    for(i = 1; i <= min; i++){
        if(num1 % i == 0 && num2 % i == 0)
            res1 = i;
    }
    i = 1;
    while((min * i) % max != 0){
        i++;
    }
    res2 = min * i;
    cout << res1 << '\n';
    cout << res2 << '\n';
}