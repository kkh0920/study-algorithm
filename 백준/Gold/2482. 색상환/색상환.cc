#include <iostream>
using namespace std;

int N, K, dp[2][1001][1001];

int solve(int start, int index, int k) {
    if(k == 0) return 1;
    if(index >= N) return 0;

    if(dp[start][index][k] != -1) return dp[start][index][k];
    
    int result = 0;
    if(!(index == N - 1 && start == 0)) {
        result += solve(start, index + 2, k - 1);
    }
    result += solve(start, index + 1, k);

    return dp[start][index][k] = result % 1000000003;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= K; j++) {
            dp[0][i][j] = -1;
            dp[1][i][j] = -1;
        }
    }

    cout << (solve(0, 2, K - 1) + solve(1, 1, K)) % 1000000003 << '\n';

    return 0;
}