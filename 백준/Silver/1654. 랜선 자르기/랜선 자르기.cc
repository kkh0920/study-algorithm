#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, K, N, max = 0, arr[10000];
    
    cin >> K >> N; 
    for(i = 0; i < K; i++){
        cin >> arr[i];
        if(max < arr[i])
            max = arr[i];
    }

    long long start = 1, end = max, middle, temp, result = 0;
    while(start <= end){
        temp = 0;
        middle = (start + end) / 2;
        for(i = 0; i < K; i++){
            temp += arr[i] / middle;
        }
        if(temp >= N){
            start = middle + 1;
            result = middle > result ? middle : result;
        }
        else 
            end = middle - 1;
    }

    cout << result << '\n';
}