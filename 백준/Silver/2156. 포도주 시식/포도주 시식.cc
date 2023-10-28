#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int result = 0, N, dp[2][10000];

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> dp[0][i];    
        dp[1][i] = dp[0][i];
    }

    dp[0][1] += dp[0][0];

    for(int i = 2; i < N; i++){
        dp[0][i] += dp[1][i - 1];
        dp[1][i] += max(dp[0][i - 2], dp[1][i - 2]);
        dp[1][i] = max(dp[1][i], max(dp[1][i - 1], dp[0][i - 1]));
    }

    cout << max(dp[0][N - 1], dp[1][N - 1]) << '\n';
}