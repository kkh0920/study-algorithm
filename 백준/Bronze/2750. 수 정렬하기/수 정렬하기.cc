#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int *ptr = new int[num];
    
    for(int i = 0; i < num; i++){
        cin >> ptr[i];
    }
    
    for(int i = 1; i < num; i++){
        for(int j = i - 1; j >= 0; j--){
            if(ptr[j] > ptr[j + 1]){
                int tmp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = tmp;
            }
        }
    }
    
    for(int i = 0; i < num; i++){
        cout << ptr[i] << '\n';
    }
}