#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, arr[500][500], dp[500][500];

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];
        }
    }

    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j <= i; j++){
            dp[i + 1][j] = max(dp[i + 1][j], arr[i + 1][j] + dp[i][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], arr[i + 1][j + 1] + dp[i][j]);
        }
    }

    int result = 0;
    for(int i = 0; i < N; i++){
        result = max(result, dp[N - 1][i]);
    }

    cout << result << '\n';
}