#include <iostream>
using namespace std;

int N, M, customer[50001], dp[50001][4];

int solve(int from, int count) {
    if (from + M * count - 1 > N) {
        return 0;
    }
    if (dp[from][count] != -1) {
        return dp[from][count];
    }

    return dp[from][count] = max(
        solve(from + 1, count),
        solve(from + M, count - 1) + customer[from + M - 1] - customer[from - 1]
    );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> customer[i];
        customer[i] += customer[i - 1];
        dp[i][1] = dp[i][2] = dp[i][3] = -1;
    }

    cin >> M;

    cout << solve(1, 3) << '\n';
    
    return 0;
}