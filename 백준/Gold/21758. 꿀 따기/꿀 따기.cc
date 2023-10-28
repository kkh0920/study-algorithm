#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, arr[100000], sum = 0, maxNum = 0;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sum += arr[i];
        maxNum = maxNum < arr[i] ? arr[i] : maxNum;
    }

    int result1 = sum - arr[0] - arr[N - 1] + maxNum;

    int loss = (arr[0] + arr[1]) * 2;
    int minLoss = loss;
    for(int i = 2; i < N; i++){
        loss -= arr[i - 1];
        loss += arr[i] * 2;
        minLoss = minLoss > loss ? loss : minLoss;
    }

    loss = (arr[N - 1] + arr[N - 2]) * 2;
    minLoss = minLoss > loss ? loss : minLoss;
    for(int i = N - 3; i >= 0; i--){
        loss -= arr[i + 1];
        loss += arr[i] * 2;
        minLoss = minLoss > loss ? loss : minLoss;
    }

    int result2 = sum * 2 - minLoss;

    cout << max(result1, result2) << '\n';
}   
