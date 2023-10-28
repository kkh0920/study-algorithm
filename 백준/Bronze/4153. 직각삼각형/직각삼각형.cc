#include <iostream>
using namespace std;

int main(){
    int i, num[3], max, maxI, prevI, c_square, a_square, b_square;
    
    while(1){
        max = 0;
        maxI = 0;
        prevI = -1;
        for(i = 0; i < 3; i++){
            cin >> num[i];
            if(max <= num[i]){
                max = num[i];
                maxI = i;
                prevI = maxI - 1;
            }
        }
        if(num[0] == 0 && num[1] == 0 && num[2] == 0)
            return 0;
        c_square = num[maxI] * num[maxI];
        switch (prevI) {
            case -1:
                a_square = num[1] * num[1];
                b_square = num[2] * num[2];
                break;
            case 0:
                a_square = num[0] * num[0];
                b_square = num[2] * num[2];
                break;
            case 1:
                a_square = num[0] * num[0];
                b_square = num[1] * num[1];
                break;
            default:
                break;
        }
        if(c_square == a_square + b_square)
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
    }
    return 0;
}