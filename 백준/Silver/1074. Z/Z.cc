#include <iostream>
#include <cmath>
using namespace std;

int cnt = 0;
bool isFirstLoop = true;

void split(int n, int r, int c){
    if(!isFirstLoop){
        if(r >= pow(2, n))
            r -= pow(2, n);
        if(c >= pow(2, n))
            c -= pow(2, n);
    }

    if(n >= 1){
        isFirstLoop = false;
        if(r < pow(2, n - 1) && c < pow(2, n - 1)){
            split(n - 1, r, c);
        }
        else if(r < pow(2, n - 1) && c >= pow(2, n - 1)){
            cnt += pow(2, 2 * (n - 1));
            split(n - 1, r, c);
        }
        else if(r >= pow(2, n - 1) && c < pow(2, n - 1)){
            cnt += 2 * pow(2, 2 * (n - 1));
            split(n - 1, r, c);
        }
        else{
            cnt += 3 * pow(2, 2 * (n - 1));
            split(n - 1, r, c);
        }
    }
    
}

int main(){
    int N, r, c;
    cin >> N >> r >> c;

    split(N, r, c);

    cout << cnt << '\n';
}