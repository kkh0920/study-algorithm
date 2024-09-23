#include <iostream>
using namespace std;

int N, K, dp[2][1001][1001], s;

int solve(int index, int k) {
    if(index == N - 1 && s == 0) return 0;
    if(index >= N) return 0;

    if(dp[s][index][k] != -1) return dp[s][index][k];
    if(k == 0) return 1;
    
    int result = 0;
    for(int i = index + 2; i < N; i++) {
        result += solve(i, k - 1);
        result %= 1000000003;
    }

    return dp[s][index][k] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            dp[0][i][j] = -1;
            dp[1][i][j] = -1;
        }
    }

    int result = 0;
    for(int i = 0; i < N; i++) {
        s = (i > 0);
        result += solve(i, K - 1);
        result %= 1000000003;
    }

    cout << result << '\n';

    return 0;
}