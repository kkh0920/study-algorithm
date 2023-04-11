#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9 - i; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[10];
    for(int i = 0; i < 10; i++){
        cin >> arr[i];
    }

    bubbleSort(arr);
    
    for(int i = 0; i < 10; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}