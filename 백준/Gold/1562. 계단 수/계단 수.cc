#include <iostream>
using namespace std;

const int MOD = 1e9;

int N, dp[101][10][1 << 10];

int solve(int n, int k, int bit) {
    if (k < 0 || k > 9) {
        return 0;
    }
    if (dp[n][k][bit] != -1) {
        return dp[n][k][bit];
    }
    if (n == 1 && bit == (1 << 10) - 1) {
        return dp[n][k][bit] = 1;
    }

    dp[n][k][bit] = (
        solve(n - 1, k + 1, bit | (1 << (k + 1))) + 
        solve(n - 1, k - 1, bit | (1 << (k - 1)))
    ) % MOD;
    
    return dp[n][k][bit];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < (1 << 10); k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    int result = 0;
    
    for (int i = 1; i <= 9; i++) {
        result += solve(N, i, 1 << i);
        result %= MOD;
    }

    cout << result << '\n';

    return 0;
}