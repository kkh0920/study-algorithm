#include <iostream>
using namespace std;

#define MIN -9999999

int N, M, D[10002], dp[10002][501];

int solve(int time, int limit) {
    if(time > N + 1 || limit > M) return MIN;
    if(dp[time][limit] != -1) return dp[time][limit];

    int res1 = solve(time + 1, limit + 1) + D[time];
    int res2 = solve(time + (limit == 0 ? 1 : limit), 0);

    return dp[time][limit] = max(res1, res2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> D[i];
        for(int j = 0; j <= M; j++) {
            dp[i][j] = -1;
        }
    }
    for(int i = 0; i <= M; i++) {
        dp[N + 1][i] = -1;
    }
    dp[N + 1][0] = 0;

    cout << solve(1, 0) << '\n';

    return 0;
}