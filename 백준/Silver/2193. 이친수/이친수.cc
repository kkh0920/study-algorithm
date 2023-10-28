#include <iostream>
using namespace std;

int main(){
    
    long long arr[91];
    int num;
    
    cin >> num;
    
    arr[1] = 1;
    arr[2] = 1;
    
    for(int i = 3; i <= num; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    cout << arr[num] << '\n';
    
}