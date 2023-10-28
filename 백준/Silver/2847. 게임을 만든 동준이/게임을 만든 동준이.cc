#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, arr[100];

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int prev = 20001, result = 0;
    for(int i = N - 1; i >= 0; i--){
        if(arr[i] >= prev){
            result += arr[i] - prev + 1;
            arr[i] -= arr[i] - prev + 1;
        }
        prev = arr[i];
    }

    cout << result << '\n';
}   