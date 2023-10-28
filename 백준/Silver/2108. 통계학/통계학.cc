#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int i, n, sum = 0, maxC = 0, c, isFirst = true;
    double average;

    cin >> n; 
    
    int *arr = new int[n];
    int *cnt = new int[n];

    for(i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
        cnt[i] = 0;
    }
    sort(arr, arr+n);
    i = 0;
    while(i < n){
        int temp = arr[i];
        c = i;
        while(arr[i] == temp && i < n){
            cnt[c]++;
            i++;
        }
        if(maxC < cnt[c])
            maxC = cnt[c];
    } 
    int r;
    for(i = 0; i < n; i++){
        if(cnt[i] == maxC){
            if(isFirst){
                r = i;
                isFirst = false;
            }
            else{
                r = i;
                break;
            }
        }
    }
    average = static_cast<double>(sum) / static_cast<double>(n);
    cout << floor(average + 0.5) << '\n';
    cout << arr[n/2] << '\n';
    cout << arr[r] << '\n';
    cout << arr[n-1] - arr[0] << '\n';

    delete[] arr;
    delete[] cnt;

    return 0;
}