#include <iostream>
using namespace std;

const int MOD = 1e9;

int N, dp[101][10][1 << 10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < (1 << 10); k++) {
                if (j == 0) {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
                } else if (j == 9) {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
                } else {
                    dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k] + dp[i - 1][j - 1][k];
                }
                dp[i][j][k | (1 << j)] %= MOD;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= 9; i++) {
        result += dp[N][i][(1 << 10) - 1];
        result %= MOD;
    }

    cout << result << '\n';

    return 0;
}