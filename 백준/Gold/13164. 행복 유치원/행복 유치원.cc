#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, arr[300000] = { 0 };

    cin >> N >> K;

    int prev, cur;
    for(int i = 0; i < N; i++){
        cin >> cur;

        if(i != 0)
            arr[i] = cur - prev;

        prev = cur;
    }

    sort(arr, arr + N);

    int result = 0;
    for(int i = 1; i <= (N - 1) - (K - 1); i++){
        result += arr[i];
    }

    cout << result << '\n';
}