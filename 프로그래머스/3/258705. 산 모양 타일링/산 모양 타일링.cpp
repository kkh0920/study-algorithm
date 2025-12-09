#include <string>
#include <vector>

using namespace std;

int N, dp[200001][2];
vector<int> top;

int solve(int index, int type) {
    if (index >= N * 2 + 1) {
        return 0;
    }
    if (dp[index][type] != -1) {
        return dp[index][type];
    }
    
    dp[index][type] = (
        solve(index + (type == 0 ? 1 : 2), 0) + 
        solve(index + (type == 0 ? 1 : 2), 1)
    );
    
    if (type == 0 && index % 2 == 1 && top[index / 2] == 1) {
        dp[index][type] *= 2;
    }
    
    return dp[index][type] % 10007;
}

int solution(int n, vector<int> tops) {
    N = n;
    top = tops;
    
    for (int i = 0; i < 2 * n + 1; i++) {
        dp[i][0] = dp[i][1] = -1;
    }
    dp[2 * n][0] = 1;
    dp[2 * n][1] = 0;
    dp[2 * n - 1][1] = 1;
    
    return (solve(0, 0) + solve(0, 1)) % 10007;
}