#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, arr[1000000];

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int result = -1;
    for(int i = N - 1; i >= 2; i--){
        if(arr[i] < arr[i - 1] + arr[i - 2]){
            result = arr[i] + arr[i - 1] + arr[i - 2];
            break;
        }
    }

    cout << result << '\n';
}   
