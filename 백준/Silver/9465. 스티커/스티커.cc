#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N, dp[2][100000];

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> N;

        for(int j = 0; j < 2; j++){
            for(int k = 0; k < N; k++){
                cin >> dp[j][k];
            }
        }

        dp[0][1] += dp[1][0];
        dp[1][1] += dp[0][0];

        for(int j = 2; j < N; j++){
            dp[0][j] += max(dp[1][j - 1], dp[1][j - 2]);
            dp[1][j] += max(dp[0][j - 1], dp[0][j - 2]);
        }

        cout << max(dp[0][N - 1], dp[1][N - 1]) << '\n';
    }
}